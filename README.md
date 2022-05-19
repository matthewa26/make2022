# MakeOHI/O 2022

This is a repository of code written during MakeOHI/O 2022.

This project utilized an Arduino Uno 3 board and an ESP8266 Wi-Fi board for the purpose of controlling a light array through an online interface. After working through how to control the light array using buttons, I modified the circuit to turn the ESP8266 module into a glorified button in the form of a web server. 

After adding in the web server component, I created an endpoint that would allow for a user on the local network to visit a website served by the server, and that website had a button that triggered the endpoint and changed the light mode. 

If I had more time and resources, I would implement a more efficient way to program the light modes to be more performant and save memory. The theme of the system was around safe driving by providing different ways to communicate with other drivers besides using the standard red, amber, and white lights on the back of a car.
