#define buzzerPin 11
#define motionSensorPin 8

long triggerTime = 0;
int alarmDuration = 5000;
int beepDuration = 2000;

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(motionSensorPin, INPUT);
}

void loop() {
  int reading = digitalRead(motionSensorPin);

  int motionLevel = reading;

  Serial.println(motionLevel);

  if (motionLevel)
  {
    triggerTime = millis();
  }

  if (millis() < triggerTime + alarmDuration
    && triggerTime > 0)
  {
    beep(beepDuration);
  }

  delay(100);
}

void beep(unsigned char delayms) {
  // This function is from
  // http://www.instructables.com/id/Arduino-YL-44-Buzzer-module/step3/Your-code/
  
  analogWrite(buzzerPin, 20);
  delay(delayms);
  analogWrite(buzzerPin ,0);
  delay(delayms); 
}

