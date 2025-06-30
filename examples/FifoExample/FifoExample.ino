#include <LSM6DS3.h>
#include <Wire.h>

//Create a instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A

void setup( void ) {
  //Over-ride default settings if desired
  myIMU.settings.gyroEnabled = 1;  //Can be 0 or 1
  myIMU.settings.gyroRange = 2000;   //Max deg/s.  Can be: 125, 245, 500, 1000, 2000
  myIMU.settings.gyroSampleRate = 833;   //Hz.  Can be: 13, 26, 52, 104, 208, 416, 833, 1666
  myIMU.settings.gyroBandWidth = 200;  //Hz.  Can be: 50, 100, 200, 400;
  myIMU.settings.gyroFifoEnabled = 1;  //Set to include gyro in FIFO
  myIMU.settings.gyroFifoDecimation = 1;  //set 1 for on /1

  myIMU.settings.accelEnabled = 1;
  myIMU.settings.accelRange = 16;      //Max G force readable.  Can be: 2, 4, 8, 16
  myIMU.settings.accelSampleRate = 833;  //Hz.  Can be: 13, 26, 52, 104, 208, 416, 833, 1666, 3332, 6664, 13330
  myIMU.settings.accelBandWidth = 200;  //Hz.  Can be: 50, 100, 200, 400;
  myIMU.settings.accelFifoEnabled = 1;  //Set to include accelerometer in the FIFO
  myIMU.settings.accelFifoDecimation = 1;  //set 1 for on /1
  myIMU.settings.tempEnabled = 1;
  
  //Non-basic mode settings
  myIMU.settings.commMode = 1;

  myIMU.settings.timestampEnabled=1;    // 1: enable timestamp ; 0: disable timestamp
  myIMU.settings.timestampFifoEnabled=1;// 1: enable write timestamp into fifo ; 0: disable
  myIMU.settings.timestampResolution=1; // 1: Set timestamp resolution ; 0: 6.4ms  1: 25us  

  //FIFO control settings
  myIMU.settings.fifoThreshold = 100;  //Can be 0 to 4096 (16 bit bytes)
  myIMU.settings.fifoSampleRate = 50;  //Hz.  Can be: 10, 25, 50, 100, 200, 400, 800, 1600, 3300, 6600
  myIMU.settings.fifoModeWord = 6;  //FIFO mode.
  //FIFO mode.  Can be:
  //  0 (Bypass mode, FIFO off)
  //  1 (Stop when full)
  //  3 (Continuous during trigger)
  //  4 (Bypass until trigger)
  //  6 (Continous mode)
  

  Serial.begin(57600);  // start serial for output
  delay(1000); //relax...
  Serial.println("Processor came out of reset.\n");
  
  //Call .begin() to configure the IMUs
  if( myIMU.begin() != 0 )
  {
	  Serial.println("Problem starting the sensor with CS @ Pin 10.");
  }
  else
  {
	  Serial.println("Sensor with CS @ Pin 10 started.");
  }
  
  Serial.print("Configuring FIFO with no error checking...");
  myIMU.fifoBegin();
  Serial.print("Done!\n");
  
  Serial.print("Clearing out the FIFO...");
  myIMU.fifoClear();
  Serial.print("Done!\n");
  
}


void loop()
{
  float temp;  //This is to hold read data
  uint16_t tempUnsigned;
  
  while( ( myIMU.fifoGetStatus() & 0x8000 ) == 0 ) {};  //Wait for watermark
 
  //Now loop until FIFO is empty.  NOTE:  As the FIFO is only 8 bits wide,
  //the channels must be synchronized to a known position for the data to align
  //properly.  Emptying the fifo is one way of doing this (this example)
  while( ( myIMU.fifoGetStatus() & 0x1000 ) == 0 ) {

    temp = myIMU.calcGyro(myIMU.fifoRead());
    Serial.print(temp);
    Serial.print(",");

    temp = myIMU.calcGyro(myIMU.fifoRead());
    Serial.print(temp);
    Serial.print(",");

    temp = myIMU.calcGyro(myIMU.fifoRead());
    Serial.print(temp);
    Serial.print(",");

    temp = myIMU.calcAccel(myIMU.fifoRead());
    Serial.print(temp);
    Serial.print(",");

    temp = myIMU.calcAccel(myIMU.fifoRead());
    Serial.print(temp);
    Serial.print(",");

    temp = myIMU.calcAccel(myIMU.fifoRead());
    Serial.print(temp);

    // The third dataset corresponds to external sensor data.
    // You need to read the third dataset first before you can read the timestamp data. 
    // Therefore, you can ignore this dataset.
    uint16_t thirdData = myIMU.fifoTimestamp();

    // The third dataset
    // timestamp in fifo
    uint32_t fifoTimestamp = myIMU.fifoTimestamp();
    Serial.print(",");
    Serial.print("FIFO time: ");
    Serial.print(fifoTimestamp);
    Serial.print("\n");
  
    delay(10); //Wait for the serial buffer to clear (~50 bytes worth of time @ 57600baud)
  
  }

  tempUnsigned = myIMU.fifoGetStatus();
  Serial.print("\nFifo Status 1 and 2 (16 bits): 0x");
  Serial.println(tempUnsigned, HEX);
  Serial.print("\n");  

}