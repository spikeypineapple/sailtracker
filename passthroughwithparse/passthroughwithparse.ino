#include <SoftwareSerial.h>
SoftwareSerial gpsData(10, 11); // RX, TX
String CurrentLine = "";
String PreviousLine = "";
//SELECT UR OUTSPUTS
String SatalitesInView = "$GPGSV";
String RecomendedMinimum = "$GPRMC";
String SataliteStatus = "$GPGSA";
String LatLong = "$GPGLL";
//
void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  gpsData.begin(9600);
}
void loop() { // run over and over
  if (gpsData.available()) {
    char character = gpsData.read();
    CurrentLine.concat(character);
    if (character == '\n') {

      PreviousLine = CurrentLine;
      CurrentLine = "";
    };
    if (PreviousLine.startsWith(LatLong)) {
      Serial.println(PreviousLine);
      
      PreviousLine = "";
    };
  };

}


