rm bit_bang.o bit_bang.hex bit_bang
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o bit_bang.o bit_bang.c
avr-gcc -mmcu=atmega328p bit_bang.o -o bit_bang
avr-objcopy -O ihex -R .eeprom bit_bang bit_bang.hex

read -p "Get ready to flash!!"
#flashing the Arduino:
#avrdude -V -F -C /etc/avrdude/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c stk500v1 -b 57600 -U flash:w:blink.hex
avrdude -C/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:bit_bang.hex:i
