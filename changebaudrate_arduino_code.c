// 1

void setup() {
  Serial.begin(1200);  // Start mit 1200 Baudrate
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readString();

    if (input.equals("SWITCH_TO_9600")) {
      Serial.println("Switching to 9600 baud...");
      Serial.flush();  // Warten, bis der Puffer leer ist
      delay(100);  // Kurze Verzögerung
      Serial.end();  // Beendet die serielle Kommunikation mit 1200 Baudrate
      Serial.begin(9600);  // Umschalten auf 9600 Baudrate
      Serial.println("Switched to 9600 baud.");
    }

    // Füge hier deinen normalen Code für die Kommunikation mit 1200 hinzu
  }
}


// 2

bool switchRequested = false;

void setup() {
  Serial.begin(1200);  // Start mit 1200 Baudrate
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readString();

    if (input.equals("SWITCH_TO_9600")) {
      Serial.println("ACK_1200");  // Bestätigung an C# senden
      switchRequested = true;
    }
  }

  if (switchRequested) {
    delay(100);  // Kurze Verzögerung, um sicherzustellen, dass die Bestätigung empfangen wurde
    Serial.flush();  // Puffer leeren
    Serial.end();  // 1200 Baudrate beenden
    Serial.begin(9600);  // Auf 9600 umschalten
    Serial.println("ACK_9600");  // Bestätigung für C# nach Baudratenwechsel
    switchRequested = false;  // Umschaltung abgeschlossen
  }
}
