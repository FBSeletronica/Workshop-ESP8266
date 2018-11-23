/*
 * Workshop - Controle dispositivos remotamente com ESP8266
 * Por: Fábio Souza
 * 
 * Exemplo 3 - webserver hello
 * Cria um webserver na placa
 */

#include <ESP8266WiFi.h>

int x = 0;

//configurações da rede
const char* ssid = "ssid";
const char* senha = "senha";

WiFiServer server(80);  //instncia o server na porta 80

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

  server.begin();
  Serial.println("Servidor inicializado!");

//mesagem de conectado
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Verifica se o cliente está conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Aguarda dados do cliente
  Serial.println("cliente");
  while (!client.available()) {
    delay(1);
  }
  
  String txt = "";   //string para montar o html
  
  txt += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
  txt += "<h1>Ola Makers!</h1>";
  txt += "<h2>Workshop ESP8266</h2>";
  txt += "<h3>teste:</h3>";
  txt += "</html>\n";
  client.print(txt);
  client.print(x);
  x++;
  
  delay(3000);
  Serial.println("");
}

