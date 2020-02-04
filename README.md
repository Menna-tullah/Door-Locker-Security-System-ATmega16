# Door-Locker-Security-System-ATmega16
![Image of project]([https://raw.githubusercontent.com/Menna-tullah/Door-Locker-Security-System-ATmega16/master/Door_locker.jpg](https://raw.githubusercontent.com/Menna-tullah/Door-Locker-Security-System-ATmega16/master/Door_locker.jpg))
# about the project

Door Locker Security System consists of two ECU’s. The first ECU called HMI responsible for interfacing with the user and the second ECU called control ECU which is responsible for the system operations and control. In the project I implemented the following drivers Keypad, LCD, DC Motor, UART, Timer, I2C and External EEPROM.



	> the master is connected to the keypad
	> the master is connected to the salve using UART 
	> the slave is connected with LCD, DC motor ( represent the door locker) 
	  and external EEPROM.
	> the EEPROM connected with the microcontroller using I2C
