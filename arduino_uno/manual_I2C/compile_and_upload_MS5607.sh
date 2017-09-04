rm bit_bang_MS5607.o bit_bang_MS5607.hex bit_bang_MS5607
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o bit_bang_MS5607.o bit_bang_MS5607.c
avr-gcc -mmcu=atmega328p bit_bang_MS5607.o -o bit_bang_MS5607
avr-objcopy -O ihex -R .eeprom bit_bang_MS5607 bit_bang_MS5607.hex

read -p "Get ready to flash!!"
#flashing the Arduino:
#avrdude -V -F -C /etc/avrdude/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c stk500v1 -b 57600 -U flash:w:blink.hex
avrdude -C/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM1 -b115200 -D -Uflash:w:bit_bang_MS5607.hex:i
