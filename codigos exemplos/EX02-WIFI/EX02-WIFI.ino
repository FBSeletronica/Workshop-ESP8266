/*
 * Workshop - Controle dispositivos remotamente com ESP8266
 * Por: Fábio Souza
 * 
 * Exemplo 2 - WIFI
 * Conecta a placa a uma REDE WIFI
 */

#include <ESP8266WiFi.h>

//configurações da rede
const char* ssid = "ssid";
const char* senha = "senha";


void setup() {
  Serial.begin(115200);  //configura comunicação serial
  delay(10);

// mensagem de debug serial
  Serial.print("Conectando para a rede  ");
  Serial.println(ssid);
  
// Iniciando a conexão WiFi
  WiFi.begin(ssid, senha);

// aguarda a conexão WIFI
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

//mesagem de conectado
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop(){
//não faz nada no loop
}
