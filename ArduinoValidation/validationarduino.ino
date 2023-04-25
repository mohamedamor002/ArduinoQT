#include <IRremote.h>
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math

#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library


#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char data; // variable containing the readed character.
int mode=-1;

#define IR_RECEIVE_PIN 9
#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define IR_BUTTON_3 71
#define IR_BUTTON_4 68
#define IR_BUTTON_5 64
#define IR_BUTTON_6 67
#define IR_BUTTON_7 7
#define IR_BUTTON_8 21
#define IR_BUTTON_9 9
#define IR_BUTTON_0 25
#define IR_BUTTON_diez 13
#define IR_BUTTON_star 22
#define IR_BUTTON_Up 24
#define IR_BUTTON_Down 82
#define IR_BUTTON_Right 90
#define IR_BUTTON_Left 8
#define IR_BUTTON_OK 28

#define IR_BUTTON_PLAY_PAUSE 64






//khar
const int PulseWire = 0;       // 'S' Signal pin connected to A0
const int LED13 = 13;          // The on-board Arduino LED
int Threshold = 550; 
PulseSensorPlayground pulseSensor;  // Creates an object


//end kharroubi



void setup() {
  // initialize the LCD
  lcd.begin();
  IRrecv IrReceiver(IR_RECEIVE_PIN);

  // Turn on the blacklight and print a message.
  lcd.backlight();
  Serial.begin(9600);
  IrReceiver.enableIRIn();

  IrReceiver.begin(IR_RECEIVE_PIN);
              // sets up to read Pulse Sensor signal every 2mS 

              pulseSensor.analogInput(PulseWire);   
	pulseSensor.blinkOnPulse(LED13);       // Blink on-board LED with heartbeat
	pulseSensor.setThreshold(Threshold);   
  pulseSensor.begin();
  lcd.clear() ;

                               
}




// repeat infinitely
void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
    case IR_BUTTON_1: {
      Serial.write("1");
      break;
    }
    case IR_BUTTON_2: {
      Serial.write("2");
      break;
    }
    case IR_BUTTON_3: {
      Serial.write("3");
      break;
    }
    case IR_BUTTON_4: {
      Serial.write("4");
      break;
    }
   
    }
  }
  if (Serial.available()) {
    lcd.clear();
    data = Serial.read();
    switch (data) {
    case '1':
      lcd.print("Ambulance  ");
      lcd.setCursor(3, 1);
      lcd.print("is on 1");


      break;
    case '2':
      lcd.print("Ambulance  ");
      lcd.setCursor(3, 1);
      lcd.print("is on 2");
 


      break;

    case '3':
      lcd.print("Ambulance  ");
      lcd.setCursor(3, 1);
      lcd.print("is on 3");
   


      break;

    case '4':
      lcd.print("Ambulance  ");
      lcd.setCursor(3, 1);
      lcd.print("is on 4");
      break;

    }

  }
 
}