const int RedNS = 9;
const int YellowNS = 11;
const int GreenNS = 13;
const int RedEW = 8;
const int YellowEW = 10;
const int GreenEW = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(RedNS, OUTPUT);
  pinMode(YellowNS, OUTPUT);
  pinMode(GreenNS, OUTPUT);
  pinMode(RedEW, OUTPUT);
  pinMode(YellowEW, OUTPUT);
  pinMode(GreenEW, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RedNS, HIGH);
  digitalWrite(GreenEW, HIGH);
  delay(10000);
  digitalWrite(GreenEW, LOW);
  digitalWrite(YellowEW, HIGH);
  delay(1000);
  digitalWrite(YellowEW, LOW);
  digitalWrite(RedNS, LOW);
  digitalWrite(GreenNS, HIGH);
  digitalWrite(RedEW, HIGH);
  delay(10000);
  digitalWrite(GreenNS, LOW);
  digitalWrite(YellowNS, HIGH);
  delay(1000);
  digitalWrite(YellowNS, LOW);
  digitalWrite(RedEW, LOW);
  
}
