#include <SoftwareSerial.h>// import the serial library



SoftwareSerial Genotronex(0, 1); // RX, TX
int ledpin=9; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

const int switchPin = 10;    // switch input
const int motor1Pin = 13;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 12;    // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 11;    // H-bridge enable pin

void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  Genotronex.println("1 and 0 will change direction of motor!");
  pinMode(ledpin,OUTPUT);

  // set the switch as an input:
  pinMode(switchPin, INPUT); 
 
  // set all the other pins you're using as outputs:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(ledpin, OUTPUT);
 
  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, HIGH);
}

void loop() {
// if the switch is high, motor will turn on one direction:
    if (digitalRead(switchPin) == HIGH) { // <--- This is where you leverage your digital pins controlled by the keyboard (bluetooth)
      digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    }
    // if the switch is low, motor will turn in the other direction:
    else { // <--- This is where you leverage your digital pins controlled by the keyboard (bluetooth)
      digitalWrite(motor1Pin, HIGH);  // set leg 1 of the H-bridge high 
      digitalWrite(motor2Pin, LOW);   // set leg 2 of the H-bridge low
    }
// put your main code here, to run repeatedly:
   if (Genotronex.available()){
BluetoothData=Genotronex.read();
   if(BluetoothData=='1'){   // if number 1 pressed ....
   digitalWrite(9,HIGH);
   Genotronex.println("LED  On D13 ON ! ");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(9,LOW);
   Genotronex.println("LED  On D13 Off ! ");
  }
  if (BluetoothData=='2'){// if number 0 pressed ....
  digitalWrite(3,HIGH);
   Genotronex.println("LED  On D13 Off ! ");
  }
}
delay(100);// prepare for next data ...
}