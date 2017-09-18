# Accelerometer_And_Gyroscope_LSM6DS3
Grove sensor 6 Axis Accelerometer And Gyroscope using LSM6DS3, [get the module here](https://www.seeedstudio.com/Grove-6-Axis-Accelerometer%26Gyroscope-p-2606.html)

## Usage


    Example           | Feature
--------------------- | -------------
HighLevelExample.ino  | Using class LSM6DS3
LowLevelExample.ino   | Using class LSM6DS3Core
Pedometer.ino         | A demo for making a pedometer 
FreeFallDetect.ino    | Detect object free falling, like a falling football

* API

Methods in class LSM6DS3   | Methods in class LSM6DS3Core
-------------------------- | -------------
readRawAccelX              | readRegisterRegion   
readRawAccelY              | readRegister         
readRawAccelZ              | readRegisterInt16  
readRawGyroX               | writeRegister       
readRawGyroY               | embeddedPage        
readRawGyroZ               | *
readFloatAccelX            | *
readFloatAccelY            | *
readFloatAccelZ            | *
readFloatGyroX             | *
readFloatGyroY             | *
readFloatGyroZ             | *
readRawTemp                | *
readTempC                  | *
readTempF                  | *
calcGyro                   | *
calcAccel                  | *

----

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 


[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/Grove_4Digital_Display)](https://github.com/igrigorik/ga-beacon)

