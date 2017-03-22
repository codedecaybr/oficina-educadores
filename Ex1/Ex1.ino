/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0

  Liga o LED por 1 segundo, em seguida desliga o LED por 1 segundo.

 */

int pin = 11;

// a função setup() é executada quando você liga ou reinicia a placa
void setup() {
  // configura o pino selecionado como saída:
  pinMode(pin, OUTPUT);
}

// a função loop() é executada para sempre:
void loop() {
  digitalWrite(pin, HIGH);   // liga o LED (escreve o nível HIGH - 5V - no pino selecionado)
  delay(1000);              // espera 1 segundo = 1000 milisegundos
  // desliga o LED (escreve o nível LOW - 0V - no pino selecionado)
  delay(1000);              // espera 1 segundo novamente
}
