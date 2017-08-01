
#replacing all tmp directory calls to be in the git repo
avr-g++ -c -g -Os -w  -fno-exceptions -ffunction-sections -fdata-sections  -flto -w -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "-I/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/arduino_pin_header.h" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.c" -o "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/log.txt"

#Compiling sketch...

avr-gcc -c -g -Os -Wall -Wextra  -fno-exceptions -ffunction-sections -fdata-sections -MMD -flto -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' "-I/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/variants/promicro" "-I/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/arduino_pin_header.h" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.c" -o "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.o"


#Compiling libraries...

#Compiling core...

#Using precompiled core

#Linking everything together...

avr-gcc -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega32u4  -o "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.elf" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.o"  "-L/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/" -lm

avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.elf" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.eep"

avr-objcopy -O ihex -R .eeprom  "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.elf" "/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/change_PWM_freq_with_switch.hex"

#Sketch uses 230 bytes (0%) of program storage space. Maximum is 28672 bytes.
#Global variables use 0 bytes (0%) of dynamic memory, leaving 2560 bytes for local variables. Maximum is 2560 bytes.

read -p "Reset the sparkfun micro and then press any key to flash the arduino"

avrdude -C/home/ashwini/.arduino15/packages/SparkFun/hardware/avr/1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -Uflash:w:/home/ashwini/git-repos/arduino/switch_pwm_freq_with_io_switch/PWM_in_c_with_my_own_header.hex:i 

#this works also I was able to replace all the extra calls to the tmp directory and do it all in c, removed all c++ specific flags. Now removed all the arduino specific gcc calls and now using system avr-gcc and avr-objcopy and avrdude

