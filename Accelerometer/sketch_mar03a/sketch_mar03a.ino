const int PWM_PIN1 = 2;
const int PWM_PIN2 = 3;
const int Lights = 13;
 
int pwm_value1;
int pwm_value2;
 
void setup() {
  pinMode(PWM_PIN1, INPUT);
  pinMode(PWM_PIN2, INPUT);
  pinMode(Lights, OUTPUT);
  Serial.begin(115200);
}
 
void loop() {
  pwm_value1 = pulseIn(PWM_PIN1, HIGH);
  pwm_value2 = pulseIn(PWM_PIN2, HIGH);
  Serial.print(pwm_value2);
  Serial.print("\t");
  Serial.print(pwm_value1);
  Serial.println();
  if((pwm_value1 >= 5600 || pwm_value1 <= 4200) || (pwm_value2 >= 5600 || pwm_value2 <= 4200)){
    digitalWrite(Lights, HIGH);
  } else{
    digitalWrite(Lights, LOW);
  }
}
