//Servo ventilator

#include <LiquidCrystal.h>
#include <Servo.h>


// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// setup the servo
Servo myservo;

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int pressure = 2;                                      // can be 1 to 3, 1 is slowest, 3 is fastest
float inhale_interval = 5000;                          // 3 seconds is the shortest interval per breath, human does 12 breaths per second or about 5 seconds
char runmode = 'R';                                    // R = run the ventilator, S is stop
long lastran = 0;                                      // time of last ran, used to calculate delay
int cnt = 0;                                           // number of press applied since reset
int pos = 0;                                           // motor position 0 to 45 degrees

void setup()
{
 lcd.begin(16, 2);
 myservo.attach(2);                                    // use pin 2 instead of pin 9 since pin 9 is used by the lcd
 lcd.setCursor(0,0);                                   // display pressure text
 lcd.print("Pressure:");
 lcd.setCursor(0,1);                                   // display interval text
 lcd.print("Interval:");
}

void loop()
{
 lcd_key = read_LCD_buttons();                         // read the buttons
 process_LCD_button();                                 // process the button pressed
 if (runmode == 'R') {
   press_mpr_bag();                                    // press the MPR bag with servo
 }
 else {
   delay(200);
 }
 display_status();                                     // display the lcd values
}

void press_mpr_bag()
{
 
 if (millis() - lastran >= inhale_interval) {          // if last press has elasped the inhale_interval, press again
   lastran = millis();                                 // last press ran by milli seconds since reset
   for (pos = 0; pos <= 45; pos += 1) {                // goes from 0 degrees to 45 degrees
     // in steps of 1 degree
     myservo.write(pos);                               // tell servo to go to position in variable 'pos'
     if (pos < 10) {
       lcd.setCursor(14,0);
       lcd.print("0");
       lcd.setCursor(15,0);
       lcd.print(pos);
     }
     else {
       lcd.setCursor(14,0);
       lcd.print(pos);
     }
     lcd.print(pos);
     delay(((6-pressure)*20)-20);                     // servo speed based on pressure of 1-3, so 3 is quickest
   }
   cnt = cnt + 1;                                     // increase press count by 1
   }
 else {
   myservo.write(0);                                  // reset the servo back to 0 degrees for exhale
   lcd.setCursor(14,0);
   lcd.print("00");
 }
 
}



// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);                          // read the value from the sensor
 if (adc_key_in > 1000) return btnNONE;               // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT;
 if (adc_key_in < 250)  return btnUP;
 if (adc_key_in < 450)  return btnDOWN;
 if (adc_key_in < 650)  return btnLEFT;
 if (adc_key_in < 850)  return btnSELECT;
 return btnNONE;                                      // when all others fail, return this...
}

void process_LCD_button()
{
 switch (lcd_key)                                     // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     if (pressure < 3) pressure = pressure + 1;
     runmode = 'S';
     break;
     }
   case btnLEFT:
     {
     if (pressure > 1) pressure = pressure - 1;
     runmode = 'S';
     break;
     }
   case btnUP:
     {
     inhale_interval = inhale_interval + 100;
     runmode = 'S';
     break;
     }
   case btnDOWN:
     {
     if (inhale_interval > 3000) inhale_interval = inhale_interval - 100;
     runmode = 'S';
     break;
     }
   case btnSELECT:
     {
     if (runmode == 'S') {
       runmode = 'R';
       lastran = millis();
     }
     else if (runmode == 'R') {
       runmode = 'S';
     }
     delay(100);
     break;
     }
     case btnNONE:
     {
     break;
     }
 }
}

void display_status()
{
 lcd.setCursor(10,0);                                  // display pressure setting
 lcd.print(pressure);
 
 lcd.setCursor(12,0);                                  // display run mode
 lcd.print(runmode);
 
 lcd.setCursor(9,1);                                   // display interval setting
 lcd.print(inhale_interval/1000);

 lcd.setCursor(14,1);                                  // display press count       
 lcd.print(cnt);
}
