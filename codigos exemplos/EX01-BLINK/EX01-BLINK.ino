/*
 * Workshop - Controle dispositivos remotamente com ESP8266
 * Por: Fábio Souza
 * 
 * Exemplo 1 - Blink LED
 * Pisca o LED onboard em intervalos de 1 segundo. 
 * Esse exemplo serve para validar a configuração da IDE e funcionamento da placa
 */

const byte LED = 2;

void setup() {
  pinMode(LED, OUTPUT);     //Configura o pino do LED como saída
}


void loop() {
  digitalWrite(LED, LOW);   //Liga LED
  delay(1000);              // aguarda 1 segundo
  digitalWrite(LED, HIGH);  // apaga LED
  delay(1000);              // Aguarda 1 segundo
}
