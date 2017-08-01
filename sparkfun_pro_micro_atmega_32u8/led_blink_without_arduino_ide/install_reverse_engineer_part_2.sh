"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics  -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "/tmp/arduino_build_569596/sketch/blinky_c_no_serial_for_avrgcc.ino.cpp" -o "/dev/null"

#Generating function prototypes...

#"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics  -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "/tmp/arduino_build_569596/sketch/blinky_c_no_serial_for_avrgcc.ino.cpp" -o "/tmp/arduino_build_569596/preproc/ctags_target_for_gcc_minus_e.cpp"

#"/home/ashwini/Downloads/arduino-1.8.3/tools-builder/ctags/5.8-arduino11/ctags" -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzns --line-directives "/tmp/arduino_build_569596/preproc/ctags_target_for_gcc_minus_e.cpp"

rm /tmp/arduino_build_569596/preproc/ctags_target_for_gcc_minus_e.cpp

#Compiling sketch...

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "/tmp/arduino_build_569596/sketch/blinky_c_no_serial_for_avrgcc.ino.cpp" -o "/tmp/arduino_build_569596/sketch/blinky_c_no_serial_for_avrgcc.ino.cpp.o"


#Compiling libraries...

#Compiling core...

#Using precompiled core

#Linking everything together...

rm /tmp/arduino_build_569596/../arduino_cache_732047/core/core_SparkFun_avr_promicro_cpu_8MHzatmega32U4_1e6cbd299ffad185359e932e3440541e.a

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-gcc" -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega32u4  -o "/tmp/arduino_build_569596/blinky_c_no_serial_for_avrgcc.ino.elf" "/tmp/arduino_build_569596/sketch/blinky_c_no_serial_for_avrgcc.ino.cpp.o"  "-L/tmp/arduino_build_569596" -lm

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/tmp/arduino_build_569596/blinky_c_no_serial_for_avrgcc.ino.elf" "/tmp/arduino_build_569596/blinky_c_no_serial_for_avrgcc.ino.eep"

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "/tmp/arduino_build_569596/blinky_c_no_serial_for_avrgcc.ino.elf" "/tmp/arduino_build_569596/blinky_c_no_serial_for_avrgcc.ino.hex"

#Sketch uses 230 bytes (0%) of program storage space. Maximum is 28672 bytes.
#Global variables use 0 bytes (0%) of dynamic memory, leaving 2560 bytes for local variables. Maximum is 2560 bytes.

/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avrdude -C/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/tmp/arduino_build_569596/blinky_c_no_serial_for_avrgcc.ino.hex:i 

#this still turns out to be succesfful!!
