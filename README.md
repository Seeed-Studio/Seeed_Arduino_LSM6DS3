Seeed Arduino LSM6DS3  [![Build Status](https://travis-ci.com/Seeed-Studio/Accelerometer_And_Gyroscope_LSM6DS3.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Accelerometer_And_Gyroscope_LSM6DS3)
---------------------------------

![](https://statics3.seeedstudio.com/images/product/105020012%203.jpg)

More detail refer to [wiki page](http://wiki.seeedstudio.com/Grove-6-Axis_AccelerometerAndGyroscope/) and [product page](https://www.seeedstudio.com/Grove-6-Axis-Accelerometer%26Gyroscope-p-2606.html)

Example
------

Example           | Feature
----------------- | ----------------------------------------------------
HighLevelExample  | Using class LSM6DS3
LowLevelExample   | Using class LSM6DS3Core
Pedometer         | A demo for making a pedometer 
FreeFallDetect    | Detect object free falling, like a falling football


API
------

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



