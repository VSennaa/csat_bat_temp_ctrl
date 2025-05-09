const int lm335Pin = 34; // entrada analógica

void setup() {
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db); // melhora precisão até ~3.6V
}

void loop() {
  int analogValue = analogRead(lm335Pin);
  float voltage = analogValue * (3.3 / 4095.0) - 0.07; // ajuste 
  float temperatureC = (voltage * 100.0) - 273.15;

  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000);
}
