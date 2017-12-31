const int links1 = 8;
const int rechts1 = 9;
const int links2 = 10;
const int rechts2 = 11;

unsigned long motorTimer = 0;

void setup()
{
  pinMode(links1, OUTPUT);
  pinMode(rechts1, OUTPUT);
  pinMode(links2, OUTPUT);
  pinMode(rechts2, OUTPUT);

  randomSeed(analogRead(0));
  
  Serial.begin(9600);
  Serial.println("Booted");
}

void loop()
{
  if(millis() > (motorTimer + 500)) {
    motorTimer = millis();
    randomPart();
  }
}

void randomPart() {
  switch (random(1,51)) {
    case 10:
      doStop();
    break;
    case 20:
      doStop();
    break;  
    case 30:
      doAchteruit();
    break;
    case 40:
      doAchteruit();
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
  digitalWrite(links1, LOW);
  digitalWrite(rechts1, LOW);
  digitalWrite(links2, HIGH);
  digitalWrite(rechts2, HIGH);
}

void doAchteruit(){
  Serial.println("State Links Entered");
  digitalWrite(links1, LOW);
  digitalWrite(rechts1, LOW);
  digitalWrite(links2, LOW);
  digitalWrite(rechts2, LOW);
}

void doVooruit(){
  Serial.println("State Rechts Entered");
  digitalWrite(links1, HIGH);
  digitalWrite(rechts1, HIGH);
  digitalWrite(links2, HIGH);
  digitalWrite(rechts2, HIGH);
}
