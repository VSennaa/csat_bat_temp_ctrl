const int lm335Pin = A0;      // Entrada do sensor LM335 no pino analógico A0
const int pwmPin = 6;         // Saída PWM para controlar os MOSFETs (pino 6, no caso do Arduino UNO)

const float targetTemp = 40.0; // Temperatura alvo em °C

void setup() {
  Serial.begin(115200);       // Inicia a comunicação serial para monitoramento
}

void loop() {
  int analogValue = analogRead(lm335Pin);  // Lê o valor analógico do sensor LM335
  float voltage = analogValue * ((5.0 / 1023.0));  // Converte o valor para tensão (5V no Arduino UNO)


  float temperatureC = (voltage * 100.0) - 273.15;
  // Controle proporcional simples
  float error = (targetTemp - temperatureC) / (targetTemp * 0.5);
  if (error < 0) error = 0;  // Evita valores negativos para o PWM
  int pwmValue = (int)(error * 255);  // Ajuste do valor PWM, limitado entre 0 e 255
  pwmValue = constrain(pwmValue, 0, 255);  // Garantir que o PWM fique entre 0 e 255
  analogWrite(pwmPin, pwmValue);  // Ajusta o valor PWM

  // Imprime os dados no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  Serial.print("PWM: ");
  Serial.println(pwmValue);

  delay(500);  // Atraso para leitura e impressão
}
