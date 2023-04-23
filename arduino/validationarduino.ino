#include <IRremote.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

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

char data;
char dataQt;
void setup() {
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  Serial.begin(9600);

  IrReceiver.begin(IR_RECEIVE_PIN);
}

// repeat infinitely
void loop() {

  if (IrReceiver.decode()) {
    IrReceiver.resume();
    delay(500);
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
    case IR_BUTTON_1: {
      data = '1';
      break;
    }
    case IR_BUTTON_2: {
      data = '2';

      break;
    }
    case IR_BUTTON_3: {
      data = '3';

      break;
    }
    case IR_BUTTON_4: {
      data = '4';

      break;
    }
    case IR_BUTTON_5: {
      data = '5';

      break;
    }
    case IR_BUTTON_6: {
      data = '6';

      break;
    }
    case IR_BUTTON_7: {
      data = '7';

      break;
    }
    case IR_BUTTON_8: {
      data = '8';

      break;
    }
    case IR_BUTTON_9: {
      data = '9';

      break;
    }
    case IR_BUTTON_0: {
      data = '0';
      break;
    }

    }
    if (Serial.availableForWrite())
      Serial.write(data);

  }
  if (Serial.available()) {
    dataQt = Serial.read();
    switch (dataQt) {
    case 1:
      lcd.print("ambulance is on 1");
      break;
    case 2:
      lcd.print("ambulance is on 2");
      break;

    }

  }

  delay(1000);

}
