// Roy Gross
// 3 - 8 - 2020
// eighth tester program
// switching between ant 1 and ant 2 because of delay problem (#2)
// no LEDs in this program
// - using tone for higher switching rate
// - I was running into the speed limit of a loop with delays
// - tone operates different than delay - switching rate of up to 8MHz (overkill)

const int k3 = 10; // pin k3


void setup() {
  // put your setup code here, to run once:
  pinMode(k3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tone(k3,5000); // switching rate of 5 KHz
}
