stty -F /dev/serial/by-id/usb-SparkFun_SparkFun_Pro_Micro-if00 1200;	
sleep 1s;
#don't need a close just need to start it
#avrdude -C/home/ashwini/git-repos/arduino/avr-1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/tmp/arduino_build_264931/blinky.ino.hex:i

#/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avrdude -C/home/ashwini/git-repos/arduino/avr-1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/tmp/arduino_build_264931/blinky.ino.hex:i

#/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avrdude -C/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/tmp/arduino_build_264931/blinky.ino.hex:i

#avrdude -C/home/ashwini/git-repos/arduino/avr-1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D Uflash:w:/tmp/arduino_build_264931/blinky.ino.hex:i

#avrdude -C/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/tmp/arduino_build_264931/blinky.ino.hex:i

#avrdude -C/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/home/ashwini/git-repos/arduino/blinky/blinky.ino.promicro.hex:i -v

avrdude -C/home/ashwini/git-repos/arduino/avr-1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/home/ashwini/git-repos/arduino/blinky/blinky.ino.promicro.hex:i -v

