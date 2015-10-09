# Accelerometer_And_Gyroscope_LSM6DS3
Grove sensor 6 Axis Accelerometer And Gyroscope using LSM6DS3

## Usage

    Example           | Feature
--------------------- | -------------
HighLevelExample.ino  | Using class LSM6DS3
LowLevelExample.ino   | Using class LSM6DS3Core

* API

class LSM6DS3   | class LSM6DS3Core
--------------- | -------------
readRawAccelX   | readRegisterRegion   
readRawAccelY   | readRegister         
readRawAccelZ   | readRegisterInt16  
readRawGyroX    | writeRegister       
readRawGyroY    | embeddedPage        
readRawGyroZ    | *
readFloatAccelX | *
readFloatAccelY | *
readFloatAccelZ | *
readFloatGyroX  | *
readFloatGyroY  | *
readFloatGyroZ  | *
readRawTemp     | *
readTempC       | *
readTempF       | *
calcGyro        | *
calcAccel       | *

----

This software is written by Loovee for for [Seeed Technology Inc.](http://www.seeed.cc) and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt/LICENSE for the details of MIT license. The TimerOne library is refered from the arduino community and its copyright follows the original.

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed is a hardware innovation platform for makers to grow inspirations into differentiating products. By working closely with technology providers of all scale, Seeed provides accessible technologies with quality, speed and supply chain knowledge. When prototypes are ready to iterate, Seeed helps productize 1 to 1,000 pcs using in-house engineering, supply chain management and agile manufacture forces. Seeed also team up with incubators, Chinese tech ecosystem, investors and distribution channels to portal Maker startups beyond.




[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/Grove_4Digital_Display)](https://github.com/igrigorik/ga-beacon)

