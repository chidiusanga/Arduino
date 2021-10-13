#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
//#define DHT_SENSOR_TYPE DHT_TYPE_21
//#define DHT_SENSOR_TYPE DHT_TYPE_22

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup( )
{
  Serial.begin(9600);
}

void loop( )
{
  float temperature;
  float humidity;

  if(dht_sensor.measure(&temperature, &humidity)){

  Serial.print((float)temperature);
  Serial.print(",");
  Serial.println((float)humidity);
  
//    Serial.print( "T = " );
//    Serial.print( temperature, 1 );
//    Serial.print( " deg. C, H = " );
//    Serial.print( humidity, 1 );
//    Serial.println( "%" );
  
//  if(temperature < 25.00)
//  {
//    Serial.print("Chidi, the temperature is ");
//    Serial.print(temperature);
//    Serial.println(". It's too cold. Close the Window!"); 
//  }
//  else
//  {
//   Serial.print("Chidi, the temperature is ");
//   Serial.print(temperature);
//   Serial.println(". It's normal.");  
//  }
  }
}
