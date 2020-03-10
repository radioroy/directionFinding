// Roy Gross
// 2 - 2 - 2020
// first tester program of ant switch eval board
// switches between RF1 and RF3 every second
// with RF3 on the same time as the onboard LED

//set k pins to numeric value
const int k2 = 9;
const int k3 = 10;
const int k1 = 11;

//defining new funcions for each "k"
void k2_h() {
  digitalWrite(k2, HIGH);
}
void k2_l() {
  digitalWrite(k2, LOW);
}

void k3_h(){
  digitalWrite(k3, HIGH);
}
void k3_l(){
  digitalWrite(k3, LOW);
}

void k1_h(){
  digitalWrite(k1, HIGH);
}
void k1_l(){
  digitalWrite(k1, LOW);
}

int setLiveRF (int RFNum){
  
}

void setup() {
  // setup (run once)


  //set pinmode for k pins to output
  pinMode(k2, OUTPUT);
  pinMode(k3, OUTPUT);
  pinMode(k1, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

k3_l();
k2_l();
k1_l();

}

// the loop function runs over and over again forever
void loop() {





  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
k2_h();
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
k2_l();
  delay(1000);                       // wait for a second
}
