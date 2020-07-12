#include <ESP8266WiFi.h>

const char *ssid = "m0nday's iphone";
const char *password = "10101010";
const char* host = "http://dimi.c2w2m2.com";
const int  buttonPin1 = D10;
const int  buttonPin2 = D11;
const int  buttonPin3 = D12;
const int  buttonPin4 = D13;
const int  buttonPin5 = D2;

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;
void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  int buttonState5 = digitalRead(buttonPin5);
  
  if (buttonState1 == HIGH) {
    // turn LED on:
    send(1);
  }
  if (buttonState2 == HIGH) {
    // turn LED on:
    send(2);
  }
  if (buttonState3 == HIGH) {
    // turn LED on:
    send(3);
  }
  if (buttonState4 == HIGH) {
    // turn LED on:
    send(4);
  }
  if (buttonState5 == HIGH) {
    // turn LED on:
    send(5);
  }
}
void send(int num) {
  ++value;
  String url = "/api/color/red";
  if(num == 1) {
    url = "/api/color/red";
    Serial.println("1");
  }
  if(num == 2) {
    url = "/api/color/green";
    Serial.println("2");
  }
  if(num == 3) {
    url = "/api/color/blue";
    Serial.println("3");
  }
  if(num == 4) {
    url = "/api/color/black";
    Serial.println("4");
  }
  if(num == 5) {
    url = "/api/erase";
    Serial.println("5");
  }

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 8083;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
//  url += streamId;
//  url += "?private_key=";
//  url += privateKey;
//  url += "&value=";
//  url += value;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  int timeout = millis() + 5000;
  while (client.available() == 0) {
    if (timeout - millis() < 0) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
}
