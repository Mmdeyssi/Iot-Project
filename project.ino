#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "DHTesp.h" 
DHTesp dht;
ESP8266WebServer server(80);
const String tempImg = "iVBORw0KGgoAAAANSUhEUgAAAIAAAACACAMAAAD04JH5AAAAPFBMVEUAAAAAAAD0/P/e9/76SVT7KzwAAAB9o7OeHSiOlpkcFhifp6wAAABUZGoAAAAAAAAAAAA2OzwAAAC9yc+E2C5SAAAAFHRSTlMA///////E//////7m/zxuFP6Z/2KBICYAAARwSURBVHic7ZvbeqQgDICLzDACnpD3f9eVgxCQOawG2+6aq3b6dfKbhJBg+Pr6Kxlm1hHSdWwe/u4fUWSaCZR5Oll/qt4inKl+CGqFEuHn8xwxOoVK0qZpKKVcuQ/Gk/Q78/dGe+MIGtqfSGCfX+gmCDUIWpxFYP2vaJMCLEZQJ8VBZ/Q3iXgCY4Ouun4TAII2RYJTnGCU6CYXRyDNH7f/MnaIOWPMHEA1DQC0USUTTJucdSRUusQA3Lhd8ECgl19ZVQDzZSI8/ZoEl5hwAPaTza4wsI6lsj9QjAf6FSAmYbEC9LVX4gw80IO9oPcEsvY6YADAKn48HhYEBEHVbdEAeP1Gl3oYMbGvvQ9KUVgJgHsDOBPIC+ACuAB+MsDSwMxejmwDzwEey0/0BQDWTvwcgPOwHRYAsu34mAnKAA/dvABIu6iDEbILYDFCkGPqdwPgyQ8F6Hv9rQD8zTKsDvDjM+EFcAFUBFC9EfUGYBpz2Z+RM4AorwA23Xmhf6wJgNod77IA2+jff5CTAbRO3gXhkMtu/RuAu5G3AIhyAVwAF8AF8EsBcLLwfoBkM+qOdWd7AGp2x59ZIAU43wJLSTZHORgEv3QVXAAXwAVwAfz3ACPJZf+bPYTt2ApWd/w7AL4Glsv+ouS7g9AOsLwDqPj63A3wlAH8aXXVYR63nPQTAEegST0C9/xhgKYM4AeaanhhgPZfROYAcJyoAsGU6bcDFBHAznUAAvyBJtvexAEmOz8DAMAsjRtowp6jGGD8+bkxQu4RwM2XOQJZwQnmKzl0v3no9naDBGR9d2Xdg+uEEQaADOpvnuDeupEeCeeJUNcidIDT79QHAm8FDcZ5ClNluwVOkNkQI7conuBOXJg6JyjcKIATZOarxe32hEABE+DtSnCCTGbPnxNIEAVos8YjWAIC+j8DaEkcK+sxw5DFHCQ3DoAEIpqgONm3V4AHVMEAqQkU8AGS/oGEGT5aiIA8CjyAwguCIYaALBogNYGOQYC1ELsQAvwDAB4XIloUSrgHF/QHAOODPkYh2pYYdmH1BOD2kwDUPw3wTTEwKAkAPlwFiABT3Avf5QER8wDHW4YgETWfZ0LERDSBcuTzvQAxFdt6BJQDz3dDWBBg1qVwoPvTekBirkI40m4ronsRoIWFMWpBYotimItI0QCwJqS4ZfEM1gFNq/L0+cU6VsdRi1K7EENfoj/oC2w9hNmcMWACT0CSzogk+m3GRD0rGggBvbH2dytEa9rjtl1/TeYakbtTRpLbNb47TsSsE5CEkPtzez7BI4EWmXp3+Sw6AK8r8TK6RQ4Qevj0Lk85/TZV4J9TMULyO1aa21kyvn4K9Ne4aNLlNsjF6bcTVlXuvLlDZ/5av7v5ePAV+WsClV+1A/r94VEl/QuB9YIouiEk4Lp3DhlYchv97uiu8v1fPymvOM3U695nhto3Hod1PlJx7SGolqt2wk64gQ3fQQmhBMiJ7KS7z9s7nKeqNzLMOQM7MCq7T6ZxZqzr7PX/EenZ/wCTnFWl2IfxgQAAAABJRU5ErkJggg==";
const String homeImg="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";
const String humImg = "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";
//192.168.4.1


void handleRoot() {
  float temperature = dht.getTemperature();
  float humidity = dht.getHumidity();
  
  const String ch1 = "<!DOCTYPE html>\n"
"<html lang=\"fr\">\n"
"  <head>\n"
"    <meta charset=\"UTF-8\" />\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n"
"    <title>Tableau de bord IoT</title>\n"
"    <style>\n"
"      body {\n"
"        font-family: Arial, sans-serif;\n"
"        text-align: center;\n"
"        background-color: #f0f0f0;\n"
"        margin: 0;\n"
"        padding: 20px;\n"
"      }\n"
"      .container {\n"
"        display: flex;\n"
"        justify-content: center;\n"
"        margin-bottom: 20px;\n"
"      }\n"
"      .card {\n"
"        background-color: white;\n"
"        border: 1px solid #ccc;\n"
"        border-radius: 10px;\n"
"        padding: 20px;\n"
"        width: 150px;\n"
"        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);\n"
"        text-align: center;\n"
"        margin: 0 10px;\n"
"      }\n"
"      .card h2 {\n"
"        margin-bottom: 10px;\n"
"        font-size: 18px;\n"
"        color: #555;\n"
"      }\n"
"      .card p {\n"
"        font-size: 24px;\n"
"        font-weight: bold;\n"
"        color: #000;\n"
"      }\n"
"\n"
"      /* Switch Styles */\n"
"      .switch {\n"
"        position: relative;\n"
"        display: inline-block;\n"
"        width: 60px;\n"
"        height: 34px;\n"
"      }\n"
"      .switch input {\n"
"        opacity: 0;\n"
"        width: 0;\n"
"        height: 0;\n"
"      }\n"
"      .slider {\n"
"        position: absolute;\n"
"        cursor: pointer;\n"
"        top: 0;\n"
"        left: 0;\n"
"        right: 0;\n"
"        bottom: 0;\n"
"        background-color: #ccc;\n"
"        transition: 0.4s;\n"
"        border-radius: 34px;\n"
"      }\n"
"      .slider:before {\n"
"        position: absolute;\n"
"        content: \"\";\n"
"        height: 26px;\n"
"        width: 26px;\n"
"        left: 4px;\n"
"        bottom: 4px;\n"
"        background-color: white;\n"
"        transition: 0.4s;\n"
"        border-radius: 50%;\n"
"      }\n"
"      input:checked + .slider {\n"
"        background-color: #2196f3;\n"
"      }\n"
"      input:checked + .slider:before {\n"
"        transform: translateX(26px);\n"
"      }\n"
"    </style>\n"
"  </head>\n"
"  <body>\n"
"<img src=\"data:image/png;base64," +homeImg+ "\" alt=\"hicon\" />\n"

"    <h1>Tableau de bord IoT</h1>\n"
"\n"
"    <div class=\"container\">\n"
"      <div class=\"card\">\n"
"<img src=\"data:image/png;base64," + tempImg + "\" alt=\"icon\" />\n"
"\n"
""
"        <h2>Température</h2>\n"
"        <p id=\"temperature\">" + String(temperature)+"°C</p>\n"
"      </div>\n"
"      <div class=\"card\">\n"
"<img src=\"data:image/png;base64," + humImg+"\"  alt=\"icon\" />\n"
""
"        <h2>Humidité</h2>\n"
"        <p id=\"humidity\">" + String(humidity) + "%</p>\n"
"      </div>\n"
"    </div>\n"
"\n"
"    <label class=\"switch\">\n"
"      <input type=\"checkbox\" id=\"ledSwitch\" onclick=\"toggleLED()\" />\n"
"      <span class=\"slider\"></span>\n"
"    </label>\n"
"\n"
"    <p id=\"status\">Led Off</p>\n"
"\n"
"    <script>\n"
"      function toggleLED() {\n"
"        var switchElement = document.getElementById(\"ledSwitch\");\n"
"        var statusText = document.getElementById(\"status\");\n"
"\n"
"        if (switchElement.checked) {\n"
"          statusText.textContent = \"Led On\";\n"
"window.location.href = \"/ledon\";"
"        } else {\n"
"          statusText.textContent = \"Led Off\";\n"
"window.location.href = \"/ledoff\";"
"        }\n"
"      }\n"
"    </script>\n"
"  </body>\n"
"</html>\n"
"";
  server.send(200, "text/html", ch1);
}
void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP("Mouhib", "012345678");

  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
  dht.setup(16, DHTesp::DHT11);
  pinMode(5,OUTPUT);
  server.on("/ledon",turnLedOn);
  server.on("/ledoff",turnLedOff);



}
void turnLedOn(){
  digitalWrite(5,HIGH);
  server.send(200,"text/html","<h1>led on</h1>");
}
void turnLedOff(){
  digitalWrite(5,LOW);
  server.send(200,"text/html","<h1>led off</h1>");
}


void loop() {
  // put your main code here, to run repeatedly:


  server.handleClient();

}
