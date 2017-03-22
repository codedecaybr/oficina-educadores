/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0

  Liga os LEDs por 1 segundo, em seguida desliga os LEDs por 1 segundo.
  Lê o LDR na porta analógica 0.
  Lê o LM35Z na porta analógica 1 e faz a média da leitura para filtrar
  ruídos.

  Nesse exercício vamos manter os LEDs externo nos pinos 11, 10 e 9 do
  Arduino. Vamos mater o LDR como sensor de luminosidade e vamos adicionar
  um LM como sensor de temperatura. O LM35Z costuma ser sensível a ruído
  eletromagnético, por isso, faremos a média de 50 leituras para eliminar
  essa variação.
 */

 int pin = 11;

// a função setup() é executada quando você liga ou reinicia a placa
void setup() {
  pinMode(pin, OUTPUT);

  Serial.begin(9600); // Inicia a comunicação serial com o computador
}

// a função loop() é executada para sempre:
void loop() {
  digitalWrite(pin, HIGH);   // liga o LED (escreve o nível HIGH - 5V - no pino selecionado)
  delay(1000);              // espera 1 segundo = 1000 milisegundos
  digitalWrite(pin, LOW);    // desliga o LED (escreve o nível LOW - 0V - no pino selecionado)
  delay(1000);              // espera 1 segundo novamente

  int soma = 0; // Guardaremos o somatorio nessa variavel
  for (int cont = 0; cont < 50; cont++) {  // repete 50 vezes
    soma = soma + analogRead(A0); // le o sensor analogico na porta A1 - escala de 0 a 1023
    delay(5); // O conversor AD do Arduino precisa de um "descanso"
  }
  float tempC = (soma * 5.0 * 100 ) / ( 1023.0 * 50 ); // calcula a média e converte para temperatura
  Serial.print("Temperatura: "); // escreve a palavra "Temperatura: " no monitor do computador
  // escreve o valor da temperatura média lida na tela do computador
  Serial.println(" C");
  delay(1000);
}
