avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o ISR_example.o ISR_example.c
avr-gcc -mmcu=atmega328p ISR_example.o -o ISR_example
avr-objcopy -O ihex -R .eeprom ISR_example ISR_example.hex

read -p "Get ready to flash!"
#flashing the Arduino:
#avrdude -V -F -C /etc/avrdude/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c stk500v1 -b 57600 -U flash:w:blink.hex
avrdude -C/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:ISR_example.hex:i
