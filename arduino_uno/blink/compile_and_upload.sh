avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink.o blink.c
avr-gcc -mmcu=atmega328p blink.o -o blink
avr-objcopy -O ihex -R .eeprom blink blink.hex

#flashing the Arduino:
#avrdude -V -F -C /etc/avrdude/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c stk500v1 -b 57600 -U flash:w:blink.hex
avrdude -C/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:blink.hex:i
