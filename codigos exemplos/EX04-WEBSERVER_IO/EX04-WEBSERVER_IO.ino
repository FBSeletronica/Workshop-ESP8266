/*
 * Workshop - Controle dispositivos remotamente com ESP8266
 * Por: Fábio Souza
 * 
 * Exemplo 4 - webserver IO
 * Aciona I/O através do browser
 */

#include <ESP8266WiFi.h>


#define OUT1 2

boolean statusOUT1 = LOW;

//configurações da rede
const char* ssid = "ssid";
const char* senha = "senha";

WiFiServer server(80);  //instncia o server na porta 80

void setup() {
  Serial.begin(115200);  //configura comunicação serial
  delay(10);

  //configura pino de saída
  pinMode(OUT1, OUTPUT);
  digitalWrite(OUT1, LOW);

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
  Serial.println("connect");
  while (!client.available()) {
    delay(1);
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  if (req.indexOf("ioon") != -1)
  {
    digitalWrite(OUT1, HIGH);
    statusOUT1 = HIGH;
  }
  else if (req.indexOf("iooff") != -1)
  {
    digitalWrite(OUT1, LOW);
    statusOUT1 = LOW;
  }

  //  Se o Servidor, conseguiu entender a chamada que fizemos acima, Retorna o Valor Lido e mostra no Navegador. 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Workshop ESP8266</h1>");

  
  if(!statusOUT1)
  client.println("<p>OUT1 <a href=\"ioon\"><button>LIGAR</button></a></p>");
  else
  client.println("<p>OUT1 <a href=\"iooff\"><button>DESLIGAR</button></a></p>");

  
  client.println("</html>");
 
  delay(10);
 
}

