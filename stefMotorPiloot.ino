#define PWM_PIN 3
#define DIRECTION_PIN 4

unsigned long motorTimer = 0;

void setup()
{
  randomSeed(analogRead(0));

  pinMode(PWM_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Booted");
}

void loop()
{
    if(millis() > (motorTimer + 500)) {
      motorTimer = millis();
      if (millis() < 7500) 
      {
        doVooruit();
      } else {
        randomPart();
      }
  }
}

void randomPart() {
  switch (random(1,51)) {
    case 10:
      doStop();
    break;
    case 20:
      doSnelVooruit();
    break;  
    case 30:
      doAchteruit();
    break;
    case 40:
      doSnelVooruit();
    break;
    case 50:
      doAchteruit();
    break;
    default:
      doVooruit();
  }
}

void doStop() {
  Serial.println("State Stop Entered");
  md10rpmSpeed(0, 1);
}

void doAchteruit(){
  Serial.println("State Links Entered");
  md10rpmSpeed(150, 0);
}

void doVooruit(){
  Serial.println("State Rechts Entered");
  md10rpmSpeed(150, 1);
}

void doSnelVooruit(){
  Serial.println("State Schnell Entered");
  md10rpmSpeed(250, 1);
}

void md10rpmSpeed(int rpm, int mDirection) {
  analogWrite(PWM_PIN, rpm);
  digitalWrite(DIRECTION_PIN, mDirection);
}
