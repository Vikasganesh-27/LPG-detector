const int ledPin = 9;
int buzzer = A0;
int gasPin = A1;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(gasPin, INPUT);
}

void loop() 
{
  int buzzVal;
  // put your main code here, to run repeatedly:
  int gasValue = analogRead(gasPin);
  Serial.println(gasValue);

  if(gasValue>=110)
  {
    Serial.println("GAS DETECTED!!!!!");
    buzzVal = 220;
    tone(buzzer, buzzVal, gasValue);
    delay(300);
    tone(buzzer, 0, gasValue);
    delay(100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(300);
    
  }

  else
  {
    buzzVal = 0;
    tone(buzzer, buzzVal, gasValue);
    digitalWrite(ledPin,LOW);
    delay(10);
  }
  delay(100);
}
