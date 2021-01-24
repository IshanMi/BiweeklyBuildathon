int red_light_pin= 9;
int green_light_pin = 10;
int blue_light_pin = 11;
int buzzer_pin = 6;
int read_pin = A0;
void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT); // Buzzer 
  pinMode(9, OUTPUT); // LED out pin R
  pinMode(10, OUTPUT); // LED out pin G 
  pinMode(11, OUTPUT); // LED out pin B
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(11, HIGH);
  delay(500); // RGB test
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void loop() {
  int average = 0;
  for (int i=0; i < 20; i++) {
    average = average + analogRead(read_pin);
    delay(25);
    }

  average = average/20;

  if (analogRead(read_pin) < 200){ // green
    RGB_color(0, 255, 0);
    tone(buzzer_pin, 1000);
    delay(2000);
    noTone(buzzer_pin);
    delay(200);
  }

  else if (analogRead(read_pin) < 500){ // yellow
    RGB_color(255, 255, 0);
    tone(buzzer_pin, 5000);
    delay(2000);
    noTone(buzzer_pin);
    delay(200); 
  }

  else if (analogRead(read_pin) > 800){ // red
    RGB_color(255, 0, 0);
    tone(buzzer_pin, 10000);
    delay(2000);
    noTone(buzzer_pin);
    delay(200); 
  }
  Serial.println(analogRead(A0));
}
