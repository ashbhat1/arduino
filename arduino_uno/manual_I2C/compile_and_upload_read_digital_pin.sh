rm read_in_digital_pin.o read_in_digital_pin.hex read_in_digital_pin
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o read_in_digital_pin.o read_in_digital_pin.c
avr-gcc -mmcu=atmega328p read_in_digital_pin.o -o read_in_digital_pin
avr-objcopy -O ihex -R .eeprom read_in_digital_pin read_in_digital_pin.hex

read -p "Get ready to flash!!"
#flashing the Arduino:
#avrdude -V -F -C /etc/avrdude/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c stk500v1 -b 57600 -U flash:w:blink.hex
avrdude -C/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM1 -b115200 -D -Uflash:w:read_in_digital_pin.hex:i
