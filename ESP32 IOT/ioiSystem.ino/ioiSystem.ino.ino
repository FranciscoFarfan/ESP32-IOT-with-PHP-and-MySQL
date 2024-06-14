
#include <WiFiManager.h>
#include <esp_timer.h>
#include <HTTPClient.h>
#include <BluetoothSerial.h>


void actividad(void* arg);//Prototipo de funcio rutinaria

BluetoothSerial SerialBT;
esp_timer_handle_t timer;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Console");
  SerialBT.setPin("1234");

  // Configuración del temporizador para que llame a la función cada 10 segundos
  const esp_timer_create_args_t periodic_timer_args = {
      .callback = &actividad, // Función a llamar
      .arg = NULL,
      .dispatch_method = ESP_TIMER_TASK, // Método de despacho del temporizador
      .name = "periodic_timer"
  };
  // Creación del temporizador
  esp_timer_create(&periodic_timer_args, &timer);
  esp_timer_start_periodic(timer, 30 * 60 * 1000000); // 30 min en microsegundos

  //Conectarse al wifi
  conectar();
}

void loop() {
    Serial.println(comunicado(2,"https://fullsendlabs.com/Pruebas/SistemaEsp.php","&texto=exito"));
    SerialBT.println(comunicado(2,"https://fullsendlabs.com/Pruebas/SistemaEsp.php","&texto=exitoso"));
    delay(5000);
}

//Funcion para conectarse a WIFI
int conectar(){
    WiFiManager wifiManager;
    
    if (!wifiManager.autoConnect("ESP32-Configuracion")) {
        Serial.println("Fallo al conectar y tiempo de espera alcanzado");
        delay(3000);
        // Reiniciar el dispositivo
        ESP.restart();
    }
    Serial.println("Conexión exitosa");
    Serial.print("Dirección IP asignada: ");
    Serial.println(WiFi.localIP());
    SerialBT.println(WiFi.localIP());
}

//Funcion para mandar POST al host
    // regresa payload en caso correcto
    // -1 (No hay internet)
    // -2 (No se pudo acceder a la pagina)

String comunicado(int estado, String url, String mensaje){
    if(WiFi.status() == WL_CONNECTED){  
        HTTPClient http;
        // Configurar la solicitud HTTP
        http.begin(url);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        
        // Realizar la solicitud POST
        String post= "confirm=1&estado=";
        post.concat(estado);
        post.concat(mensaje);
        int httpResponseCode =  http.POST(post);
        
        
        // Verificar si la solicitud fue exitosa  
        Serial.print(httpResponseCode);
        if (httpResponseCode > 0) {
            String payload = http.getString();

            return(payload);
        }else{
            return("-2");
        }
        http.end();
    }else{
        return("-1");
    }

}

void actividad(void* arg){
    Serial.println("rutinario");
    comunicado(2,"https://fullsendlabs.com/Pruebas/SistemaEsp.php","");
}
