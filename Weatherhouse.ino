#include <Bonezegei_DHT11.h>
Bonezegei_DHT11 dht(2);
const int Min = 0; //Sensor minimum of DHT11
const int Max = 1024; //Sensor maximum of DHT11


void setup() {
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("Weatherhouse test initiated");
  delay(1000);
}

void loop() {
  //DHT11 part
  if(dht.getData()){
    float tempDeg = dht.getTemperature();
    float tempFar = dht.getTemperature(true);
    int hum = dht.getHumidity();
    Serial.print("Celsius: ");
    Serial.println(tempDeg);
    Serial.print("Fahrenheit: ");
    Serial.println(tempFar);
    Serial.print("Humidity: ");
    Serial.println(hum);
    Serial.println("-------------");
  }
  //MH-RD part
  int SensorReading = analogRead(A0); //Reads the analogue pin A0 is connected to
  int range = map(SensorReading,Min,Max,0,3);
  bool RD; //RainDetector
  switch(range){
        case 1: //Sensor is wet
        Serial.println("Im detecting some interference. It might be raining\n");
        RD = true;
        break;
      default: //Sensor is dry
        RD = false;
        break;
  }
  delay(100)
}