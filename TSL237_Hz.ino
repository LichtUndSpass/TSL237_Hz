#include <FreqMeasure.h>

void setup()
{
  Serial.begin(9600);
}

float read_TSL237_Hz()
{
  double sum = 0; //Summe von 30 Messwerten
  double frequenz = 0.0f;//gemessene Frequenz des Sensors
  int count = 0; //wird unten in der for Schleife verwendet

  FreqMeasure.begin();////Frequenz-Messung beenden
  for (count = 0; count < 30; count++) //30 Messwerte werden erfasst
  {
    while (!FreqMeasure.available())
    {
      //auf neuen Messwert warten
    }
    // Einzelmessungen summieren
    sum = sum + FreqMeasure.read();
  }
  FreqMeasure.end();//Frequenz-Messung beenden
  frequenz = F_CPU / (sum / count);//F_CPU ist die Taktfrequenz des Arduinos

  return frequenz;
}

void loop()
{
  float f = read_TSL237_Hz();
  Serial.println(f);
}
