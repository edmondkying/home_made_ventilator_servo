# home_made_ventilator_servo
Home made ventilator, servo arm presses MPR bag
Home made ventilator made with off the shelf parts for less than $50 with no 3D printed parts whatsoever. Just these parts and 15 minutes.


This is a home made ventilator. It is very crude but it works okay on a test dummy and a lung tester.  The servo arm presses down on
the MPR bag and releases.  Similar to if you're pressing the MPR bag by hand.


Please understand that this is not made for professional use. It is a desperate measure for desperate time. Sometimes having one is better than NOTHING at all. Please do not blame me for anything, just trying to do what I can. With 5 seconds for inhale interval will
yield about 12 breaths per minute.  You get about 500ml of air which is average size breath. So just adjust the time for more or less air. You can use a lung tester to test amount of air and pressure.  My next revision is to add an air pressure sensor so that if the user take a small weak breath, it will trigger the servo to press the MPR bag while the system will still maintain the press interval if no breath is detected.

assembly, should take about 15 minutes

step 1) connect usb port of arduino to computer and load the program

step 2) connect the LCD sheild to the Arduino Uno R3

step 3) connect the servo brackets to the mp995 servo with a circular servo arm

step 4) connect the servo ground to Uno's ground and 8v psu ground, servo power 8v psu, servo signal to pin 2, mount on side of the box

step 5) mount the servo assembly mount to the wood box in the bottom mid side section of the wood box with long screws. You can use two servos if you want, just run them thru a Y servo cable.  But one is okay I think.

step 6) place the MPR bag inside the wood box over the servo arm, loop the inhale/exhale lines to the handle holes of the wood box to secure.  You might need to cut the holes bigger.


to turn on 

step 1) connect 12vdc power supply to Uno's power plug

to adjust

* press up/down button to adjust breath interval time between 2 seconds and up, default is 5 seconds
* press left/right button to adjust pressure/speed of the arm 1-3, default is 1 which is the slowest
* press select to pause/run the ventilator

LCD display
* there is a count on the right upper corner to show you how many presses the ventilator did since last reset
* there is a step count on the right lower corner to show you 0-45 degress the servo is at during each press

Parts: (total should be about $75 USD)

https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_4?crid=ODLFM80RSUBZ&dchild=1&keywords=arduino+uno+r3&qid=1586038192&sprefix=ard%2Caps%2C156&sr=8-4 x 1

https://www.amazon.com/gp/product/B00OGYXN8C/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1 x 1

https://www.amazon.com/ANNIMOS-Digital-Voltage-Stainless-Waterproof/dp/B07KTS4L94/ref=sr_1_5?crid=2TKGQOU3ESP6I&dchild=1&keywords=high%2Btorque%2Bservo&qid=1586200090&sprefix=high%2Btor%2Caps%2C164&sr=8-5&th=1

https://www.amazon.com/gp/product/B07HQB95VY/ref=ppx_yo_dt_b_asin_title_o01_s01?ie=UTF8&psc=1 x 1

https://www.vitalitymedical.com/resuscitator-bag-with-nasal-oral-mask.html x 1

https://www.amazon.com/gp/product/B07HMKW45H/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1 x .25

https://www.amazon.com/SMAKN-8-4V-1A-Power-Adapter/dp/B01EHFCA60 x 1

some wires


You can switch to compatible components at will

