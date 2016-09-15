/*
 Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

 The mouse movement is always relative. This sketch reads
 four pushbuttons, and uses them to set the movement of the mouse.

 WARNING:  When you use the Mouse.move() command, the Arduino takes
 over your mouse!  Make sure you have control before you use the mouse commands.

 */

const int LED_PIN = 13;

void setup() { // initialize the buttons' inputs:
  Serial.begin(9600);
  // initialize mouse control:
  Mouse.begin();
  pinMode(LED_PIN, OUTPUT);
}


void blink_led() {
   digitalWrite(LED_PIN, HIGH);
   delay(250);
   digitalWrite(LED_PIN, LOW);
}

void flash(){
  blink_led();
  delay(250);
  blink_led();
  delay(250);
  blink_led();
}

void loop() {
  // Every 1 mins just jiggle the mouse
  delay(60000);
  flash();
  Mouse.move(0,10);
  delay(10);
  Mouse.move(0, -10);
  
  // use serial input to control the mouse:
  if (Serial.available() > 0) {
    char inChar = Serial.read();

    switch (inChar) {
      case 'x':
        // Backdoor if things go really weird Sleep for 30 seconds
        delay(30000);
      case 'u':
        // move mouse up
        blink_led();
        Mouse.move(0, -40);
        break;
      case 'd':
        // move mouse down
        blink_led();
        Mouse.move(0, 40);
        break;
      case 'l':
        // move mouse left
        blink_led();
        Mouse.move(-40, 0);
        break;
      case 'r':
        // move mouse right
        blink_led();
        Mouse.move(40, 0);
        break;
      case 'm':
        // perform mouse left click
        blink_led();
        Mouse.click(MOUSE_LEFT);
        break;
    }
  }
}

