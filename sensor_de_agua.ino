const int sensorPin = A0;
const int buzzerPin = 8;

const int greenLed = 3;
const int yellowLed = 4;
const int redLed = 5;

// Levels
int level30 = 510;
int level50 = 550;
int level80 = 570;

float alpha = 0.08;

float filteredValue = 0;

// BUZZER CONTROL

unsigned long previousTime = 0;
bool buzzerState = false;

void setup() {

  pinMode(buzzerPin, OUTPUT);

  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  Serial.begin(9600);

  // Initialize filter
  filteredValue = analogRead(sensorPin);
}

void loop() {

  //Sensor reading
  int reading = analogRead(sensorPin);

  // Exponential filter

  filteredValue = (alpha * reading) +
                  ((1 - alpha) * filteredValue);

  int sensorValue = (int)filteredValue;

  Serial.print("Reading: ");
  Serial.print(reading);

  Serial.print("   Filtered: ");
  Serial.println(sensorValue);

  //low level
  if(sensorValue < level30) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);

    noTone(buzzerPin);
  }
  //medium level
  else if(sensorValue < level50) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);

    intermittentBuzzer(700);
  }
  // high level
  else if(sensorValue < level80) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);

    intermittentBuzzer(150);
  }
  // critical level
  else {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);

    tone(buzzerPin, 2000);
  }

  delay(10);
}

// Intermittent Buzzer
void intermittentBuzzer(int interval) {

  unsigned long currentTime = millis();

  if(currentTime - previousTime >= interval) {

    previousTime = currentTime;

    buzzerState = !buzzerState;

    if(buzzerState) {

      tone(buzzerPin, 1500);

    } else {

      noTone(buzzerPin);

    }
  }
}