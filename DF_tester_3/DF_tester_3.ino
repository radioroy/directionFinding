// Roy Gross
// 2 - 4 - 2020
// third tester program



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
    Serial.println("RF1");
  }
  else if (RFNum == 2) {
    k2_l();
    k3_h();
    k1_l();
    //RF2
    //L H L
    Serial.println("RF2");
  }
  else if (RFNum == 3) {
    k2_h();
    k3_l();
    k1_l();
    //RF3
    //H L L
    Serial.println("RF3");
  }
  else if (RFNum == 4) {
    k2_h();
    k3_h();
    k1_l();
    //RF4
    //H L L
    Serial.println("RF4");
  }
  else {
    k2_l();
    k3_l();
    k1_h();
    //None
    //X X H
    Serial.println("none");
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
  Serial.begin(9600);

  //set pinmode for k pins to output
  pinMode(k2, OUTPUT);
  pinMode(k3, OUTPUT);
  pinMode(k1, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  k3_h();
  k2_l();
  k1_l();

}

// the loop function runs over and over again forever
void loop() {


  Serial.println("loop");
  delay(100);
  //setLiveRF(0);


  digitalWrite(LED_BUILTIN, HIGH);   // 
  setLiveRF(4);
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // 
  setLiveRF(0);
  delay(1000);                       // wait for a second

}
