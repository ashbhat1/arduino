rm manual_I2C.o manual_I2C.hex manual_I2C
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o manual_I2C.o manual_I2C.c
avr-gcc -mmcu=atmega328p manual_I2C.o -o manual_I2C
avr-objcopy -O ihex -R .eeprom manual_I2C manual_I2C.hex

read -p "Get ready to flash!!"
#flashing the Arduino:
#avrdude -V -F -C /etc/avrdude/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c stk500v1 -b 57600 -U flash:w:blink.hex
avrdude -C/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:manual_I2C.hex:i
