#replacing all tmp directory calls to be in the git repo
"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics  -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "-I/home/ashwini/Downloads/arduino-1.8.3/hardware/arduino/avr/cores/arduino" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.cpp" -o "/dev/null"

#Generating function prototypes...

#"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics  -flto -w -x c++ -E -CC -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "/tmp/arduino_build_569596/sketch/blinky_c_no_serial_for_avrgcc.ino.cpp" -o "/tmp/arduino_build_569596/preproc/ctags_target_for_gcc_minus_e.cpp"

#"/home/ashwini/Downloads/arduino-1.8.3/tools-builder/ctags/5.8-arduino11/ctags" -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzns --line-directives "/tmp/arduino_build_569596/preproc/ctags_target_for_gcc_minus_e.cpp"

rm /tmp/arduino_build_569596/preproc/ctags_target_for_gcc_minus_e.cpp

#Compiling sketch...

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/Downloads/arduino-1.8.3/hardware/arduino/avr/cores/arduino" "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.cpp" -o "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.o"


#Compiling libraries...

#Compiling core...

#Using precompiled core

#Linking everything together...

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-gcc" -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega32u4  -o "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.elf" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.o"  "-L/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main" -lm

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.elf" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.eep"

"/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.elf" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.hex"

#Sketch uses 230 bytes (0%) of program storage space. Maximum is 28672 bytes.
#Global variables use 0 bytes (0%) of dynamic memory, leaving 2560 bytes for local variables. Maximum is 2560 bytes.

read -p "Reset the sparkfun micro and then press any key to flash the arduino"

/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/bin/avrdude -C/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/using_arduino_main/arduino_test.hex:i 

#this works also I was able to replace all the extra calls to the tmp directory and do it all in c
