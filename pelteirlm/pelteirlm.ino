const int lm335Pin = 34;     // Entrada do sensor LM335
const int pwmPin = 16;       // Saída PWM para controlar os MOSFETs (ajuste conforme seu circuito)

const float targetTemp = 40.0; // Temperatura alvo em °C

void setup() {
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db); // Para leitura mais precisa até 3.6V
  
}

void loop() {
  int analogValue = analogRead(lm335Pin);
  float voltage = analogValue * (3.3 / 4095.0) - 0.07; // Ajuste de offset
  float temperatureC = (voltage * 100.0) - 273.15;


  // Controle proporcional simples
  float error = (targetTemp - temperatureC) / (targetTemp*0.5);
  if(error < 0) error = 0;
  int pwmValue = (int)(error * 255); // Ganha de 10, limitado entre 0 e 255
  analogWrite(pwmPin, pwmValue);

  Serial.print("Temperatura:\t");
  Serial.print(temperatureC);
  Serial.println(" °C");
  Serial.print("PWM: \t");
  Serial.println(pwmValue);

  delay(500);
}
