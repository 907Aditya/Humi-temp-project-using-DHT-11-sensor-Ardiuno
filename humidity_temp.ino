#include "DHT.h" //It includes all lib

#define DHTPIN 2 


#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("project temp_humi test");
 
  dht.begin();// starts taking data
}

void loop() {

  delay(2000);


  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float f = dht.readTemperature(true);//give significance
  

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hi = dht.computeHeatIndex(f, h); //predefined fuction to compute heat index

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");
}

