/* 
Name: Rubbaldeep Sandhu
Statement of Authorship: I certify that this is my own code and,
I have not broken any rules concerning Academic Dishonesty
*/

#include <Arduino.h>

void setup() {
    Serial.begin(115200);
}

void loop() {
    int iVal;
    float temperature;
    String temperatureStatus;

    // Read the analog value
    iVal = analogRead(A0);

    // Convert 0-1023 to 0-50 degrees Celsius
    temperature = (iVal / 1023.0) * 50.0;

    // Decide the temperature status
    if (temperature < 10) {
        temperatureStatus = "Cold!";
    }
    else if (temperature >= 10 && temperature < 15) {
        temperatureStatus = "Cool";
    }
    else if (temperature >= 15 && temperature < 25) {
        temperatureStatus = "Perfect";
    }
    else if (temperature >= 25 && temperature < 30) {
        temperatureStatus = "Warm";
    }
    else if (temperature >= 30 && temperature < 35) {
        temperatureStatus = "Hot";
    }
    else {
        temperatureStatus = "Too Hot!";
    }

    // Print the result
    Serial.println(
        "Digitized output of " + String(iVal) +
        " is equivalent to a temperature input of " +
        String(temperature, 2) +
        " deg. C, which is " +
        temperatureStatus
    );

    // Wait 2 seconds
    delay(2000);
}
