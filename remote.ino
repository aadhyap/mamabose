/**
   PostHTTPClient.ino

    Created on: 21.11.2016

*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define USE_SERIAL Serial

ESP8266WebServer server(80);
boolean done = false;


void handleRoot() {
  //digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp8266!");

  //digitalWrite(led, 0);
}


void handleNotFound() {

  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(200, "text/plain", message);

  String my_arg = "";
  my_arg += server.uri();
  my_arg.trim();
  if(my_arg.equals("/arm")){
    done = false;
  }

  if(my_arg.equals("/fire")){
  fire();
  delay(9000);
  water();
  }

  if(my_arg.equals("/happy")){
  happy();
  }

  if(my_arg.equals("/sad")){
  sad();
  }
  if(my_arg.equals("/angry")){
  angry();
  }
}



/* this can be run with an emulated server on host:
        cd esp8266-core-root-dir
        cd tests/host
        make ../../libraries/ESP8266WebServer/examples/PostServer/PostServer
        bin/PostServer/PostServer
   then put your PC's IP address in SERVER_IP below, port 9080 (instead of default 80):
*/
//#define SERVER_IP "10.0.1.7:9080" // PC address with emulation on host
#define SERVER_IP "192.168.1.14:8090"

#ifndef STASSID
#define STASSID "mauiSpot3"
#define STAPSK  "baldeagle"
#endif



void hello(){
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://"  SERVER_IP  "/speaker"); //HTTP
    http.addHeader("Content-Type", "application/xml");

    USE_SERIAL.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body
    int httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg</app_key><url>http://192.168.1.10:8100/greetings/hello.ogg</url><service>service text</service><reason>reason text</reason><message>age text</message><volume>70</volume></play_info>");

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        USE_SERIAL.println("received payload:\n<<");
        USE_SERIAL.println(payload);
        USE_SERIAL.println(">>");
      }
    } else {
      USE_SERIAL.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

void happy(){
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    USE_SERIAL.print("[HThttpTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://"  SERVER_IP  "/speaker"); //HTTP
    http.addHeader("Content-Type", "application/xml");

    USE_SERIAL.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body
    int card = int(random(0,3));
    int httpCode = 0;

    if (card == 0){
          httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
          </app_key><url>http://192.168.1.10:8100/happy/walker.ogg</url>\
          <service>service text</service><reason>reason text</reason><message>age text\
          </message><volume>70</volume></play_info>");
    }
    else if (card == 1){
      httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
      </app_key><url>http://192.168.1.10:8100/happy/Faded-Heart.ogg</url>\
      <service>service text</service><reason>reason text</reason><message>age text\
      </message><volume>70</volume></play_info>");

    }
    else {
      httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
      </app_key><url>http://192.168.1.10:8100/happy/The-Start-Of-Something.ogg</url>\
      <service>service text</service><reason>reason text</reason><message>age text\
      </message><volume>70</volume></play_info>");

    }


    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        USE_SERIAL.println("received payload:\n<<");
        USE_SERIAL.println(payload);
        USE_SERIAL.println(">>");
      }
    } else {
      USE_SERIAL.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

void angry(){
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://"  SERVER_IP  "/speaker"); //HTTP
    http.addHeader("Content-Type", "application/xml");

    USE_SERIAL.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body
    int card = int(random(0,3));
    int httpCode = 0;
    if (card == 0){
          httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
          </app_key><url>http://192.168.1.10:8100/angry/Glory.ogg</url>\
          <service>service text</service><reason>reason text</reason><message>age text\
          </message><volume>70</volume></play_info>");
    }
    else if (card == 1){
       httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
      </app_key><url>http://192.168.1.10:8100/angry/Milk-Snow-Animal.ogg</url>\
      <service>service text</service><reason>reason text</reason><message>age text\
      </message><volume>70</volume></play_info>");

    }
    else {
       httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
      </app_key><url>http://192.168.1.10:8100/angry/Muse-Uprising.ogg</url>\
      <service>service text</service><reason>reason text</reason><message>age text\
      </message><volume>70</volume></play_info>");

    }


    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        USE_SERIAL.println("received payload:\n<<");
        USE_SERIAL.println(payload);
        USE_SERIAL.println(">>");
      }
    } else {
      USE_SERIAL.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

void sad(){
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://"  SERVER_IP  "/speaker"); //HTTP
    http.addHeader("Content-Type", "application/xml");

    USE_SERIAL.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body
    int card = int(random(0,2));
int httpCode = 0;
    if (card == 0){
           httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
          </app_key><url>http://192.168.1.10:8100/sad/I_Will_Wait.ogg</url>\
          <service>service text</service><reason>reason text</reason><message>age text\
          </message><volume>70</volume></play_info>");
    }
    else{
      httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg\
      </app_key><url>http://192.168.1.10:8100/sad/Coldplay_Yellow.ogg</url>\
      <service>service text</service><reason>reason text</reason><message>age text\
      </message><volume>70</volume></play_info>");

    }



    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        USE_SERIAL.println("received payload:\n<<");
        USE_SERIAL.println(payload);
        USE_SERIAL.println(">>");
      }
    } else {
      USE_SERIAL.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

void fire(){
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://"  SERVER_IP  "/speaker"); //HTTP
    http.addHeader("Content-Type", "application/xml");

    USE_SERIAL.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body
    int httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg</app_key><url>http://192.168.1.10:8100/greetings/fire.ogg</url><service>service text</service><reason>reason text</reason><message>age text</message><volume>70</volume></play_info>");

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        USE_SERIAL.println("received payload:\n<<");
        USE_SERIAL.println(payload);
        USE_SERIAL.println(">>");
      }
    } else {
      USE_SERIAL.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

void water(){
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://"  SERVER_IP  "/speaker"); //HTTP
    http.addHeader("Content-Type", "application/xml");

    USE_SERIAL.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body
    int httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg</app_key><url>http://192.168.1.10:8100/greetings/water.ogg</url><service>service text</service><reason>reason text</reason><message>age text</message><volume>70</volume></play_info>");

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        USE_SERIAL.println("received payload:\n<<");
        USE_SERIAL.println(payload);
        USE_SERIAL.println(">>");
      }SE_SERIAL.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body
    int httpCode = http.POST("<play_info><app_key>3ZKYSw3X6GdOrAHh6F0SZDg225OiHKDg</app_key><url>http://192.168.1.10:8100/greetings/water.ogg</url><service>service text</service><reason>reason text</reason><message>age text</message><volume>70</volume></play_info>");

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        USE_SERIAL.println("received payload:\n<<");
        USE_SERIAL.println(payload);
        USE_SERIAL.println(">>");
      }
    } else {
      U
    } else {
      USE_SERIAL.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}


void setup() {

  USE_SERIAL.begin(115200);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  WiFi.begin(STASSID, STAPSK);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    USE_SERIAL.print(".");
  }
  USE_SERIAL.println("");
  USE_SERIAL.print("Connected! IP address: ");
  USE_SERIAL.println(WiFi.localIP());

  delay(5000);

  pinMode(D3, INPUT);



  //Server httpCode
  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });



  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  digitalWrite(D7, HIGH);
  digitalWrite(D6, HIGH);


}

void loop() {
  String out = "sensor: ";
  out += digitalRead(D8);

  Serial.println(out);
  if(digitalRead(D8) == HIGH && !done){
    hello();
    delay(3000);
    done = true;
  }

  server.handleClient();
  MDNS.update();

}
