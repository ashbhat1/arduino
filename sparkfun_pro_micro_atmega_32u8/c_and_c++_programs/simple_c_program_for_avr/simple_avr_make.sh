#avr-gcc -c -g -Os -Wall -Wextra -fno-exceptions -ffunction-sections -fdata-sections -MMD -flto -mmcu=atmega32u4 -DF_CPU=8000000L -DARDUINO=10803 -DARDUINO_AVR_PROMICRO -DARDUINO_ARCH_AVR  -DUSB_VID=0x1b4f -DUSB_PID=0x9204 '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="SparkFun Pro Micro"' simple_prog_for_avr.c -o simple_prog_for_avr.o


avr-gcc -c -g -Os -Wall -Wextra -fno-exceptions -ffunction-sections -fdata-sections -MMD -flto -mmcu=atmega32u4 -DF_CPU=8000000L simple_prog_for_avr.c -o simple_prog_for_avr.o
avr-gcc -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega32u4  -o simple_prog_for_avr.elf simple_prog_for_avr.o
avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  simple_prog_for_avr.elf simple_prog_for_avr.eep
avr-objcopy -O ihex -R .eeprom  simple_prog_for_avr.elf simple_prog_for_avr.hex



#avr-gcc -Wall -g -Os -mmcu=atmega32u4 -o simple_prog_for_avr.bin simple_prog_for_avr.c
#avr-size -C simple_prog_for_avr.bin
#avr-objcopy -j .text -j .data -O ihex simple_prog_for_avr.bin simple_prog_for_avr.hex

stty -F /dev/ttyACM1 1200;	
sleep 1s;
avrdude -C/home/ashwini/git-repos/arduino/avr-1.1.6/avrdude.conf -v -patmega32u4 -cavr109 -P/dev/ttyACM1 -b57600 -D -Uflash:w:/home/ashwini/git-repos/arduino/c_and_c++_programs/simple_c_program_for_avr/simple_prog_for_avr.hex:i -v
