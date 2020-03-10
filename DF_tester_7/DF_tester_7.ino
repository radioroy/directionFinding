// Roy Gross
// 2 - 13 - 2020
// seventh tester program
// switching between ant 1 and ant 2 because of delay problem (#2)
// LEDSs indicate which antenna is connected to the radio

//sets switching time delay
//int hzz = 10000;
int sdelay = 5;

int analogPin = A0;
int potVal = 0;

int ledR = 6;
int ledY = 7;
int ledG = 4;
int ledB = 5;

//set k pins to numeric value
const int k2 = 9;
const int k3 = 10;
const int k1 = 11;

//defining kx_y functions with x being the control port and y being h (high) or l (low)
void k2_h() {
  digitalWrite(k2, HIGH);
}
void k2_l() {
  digitalWrite(k2, LOW);
}

void k3_h() {
  digitalWrite(k3, HIGH);
}
void k3_l() {
  digitalWrite(k3, LOW);
}

void k1_h() {
  digitalWrite(k1, HIGH);
}
void k1_l() {
  digitalWrite(k1, LOW);
}

int setLiveRF (int RFNum) {
  if (RFNum == 1) {
    k2_l();
    k3_l();
    k1_l();
    //RF1
    //L L L
    //Serial.println("RF1");
    digitalWrite(ledY, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
  }
  else if (RFNum == 2) {
    k2_l();
    k3_h();
    k1_l();
    //RF2
    //L H L
    //Serial.println("RF2");
    digitalWrite(ledB, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
  }
  else if (RFNum == 3) {
    k2_h();
    k3_l();
    k1_l();
    //RF3
    //H L L
    //Serial.println("RF3");
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
  }
  else if (RFNum == 4) {
    k2_h();
    k3_h();
    k1_l();
    //RF4
    //H L L
    //Serial.println("RF4");
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledB, LOW);
  }
  else {
    k2_l();
    k3_l();
    k1_h();
    //None
    //X X H
    //Serial.println("none");
  }
}



int antRotate (int antNum, int antSpeed) {
setLiveRF(1);
delay(antSpeed);
setLiveRF(2);
delay(antSpeed);
setLiveRF(3);
delay(antSpeed);
setLiveRF(4);
delay(antSpeed);
}

void setup() {
  // setup (run once)
  Serial.begin(115200);

  //set pinmode for k pins to output
  pinMode(k2, OUTPUT);
  pinMode(k3, OUTPUT);
  pinMode(k1, OUTPUT);
  pinMode(analogPin, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  k3_h();
  k2_l();
  k1_l();

}

//  the loop function runs over and over again forever
void loop() {

potVal = analogRead(analogPin);  // read the input pin
  //Serial.println(potVal);          // debug value

int potDelay = (potVal / 10);
Serial.println(potDelay);

if (potDelay < 1){
  potDelay = 1;
}
else if (potDelay > 60){
  do {
    //analogRead(analogPin);
    potVal = analogRead(analogPin);
    potDelay = (potVal / 10);
    Serial.println(potDelay);
  // statement block
} while (potDelay > 60);
  }

//  Serial.println(potDelay);
  
  //Serial.println("loop");

  //setLiveRF(0);




  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  setLiveRF(2);
  delay(potDelay);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  setLiveRF(1);
  delay(potDelay);                       // wait for a second

}
