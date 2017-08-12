rm USART_example.o USART_example.hex USART_example
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o USART_example.o USART_example.c
avr-gcc -mmcu=atmega328p USART_example.o -o USART_example
avr-objcopy -O ihex -R .eeprom USART_example USART_example.hex

read -p "Get ready to flash!!"
#flashing the Arduino:
#avrdude -V -F -C /etc/avrdude/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c stk500v1 -b 57600 -U flash:w:blink.hex
avrdude -C/home/ashwini/Downloads/arduino-1.8.3/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:USART_example.hex:i
