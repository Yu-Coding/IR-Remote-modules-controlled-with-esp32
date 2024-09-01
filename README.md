# IR-Remote-modules-controlled-with-esp32
This is a example project that using a esp32 microcontronller to send string to a commerical IR Remote modules to control the device like AC...

Here is a story. One day, my AC got worng when it works. It always close after running for a few mintues. Called a repairer to fix it up but it needs appointment to wait. So, I started this project, using the esp32 on my hand and a IR remote modules. Due to the coding complexity of receiving the IR signal and transmitting the IR signal to remote device, I directly used the commerical integrated IR remote module to advoid coding on it.

What I needed is, firstly let the IR remote module study IR signal from remoter and test if it could transmit the IR signal to AC, then using the microcontroller to send the string data to the commerical intergrated IR remote module when the set time reached every 20 minutes. The string data in the example is the one that asks the IR remote module to transmit the IR signal. The string data could be changed according to what function it would need.

HOW TO USE:

Opening the Arduino IDE, importing the main.ino file, selecting esp32 or other Arduino microcontroller to be uploaed with the program.
