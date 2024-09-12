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

// 3: Verwende einen Pin, der die Baudrate steuert
const int baudRatePin = 2;  // Pin, der die Baudrate steuert

void setup() {
  pinMode(baudRatePin, INPUT);  // Setze den Pin als Eingang
  
  if (digitalRead(baudRatePin) == HIGH) {
    Serial.begin(9600);  // Wenn der Pin HIGH ist, benutze 9600 Baudrate
    Serial.println("Using 9600 baud.");
  } else {
    Serial.begin(1200);  // Wenn der Pin LOW ist, benutze 1200 Baudrate
    Serial.println("Using 1200 baud.");
  }
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readString();
    Serial.println("Received: " + input);
    
    // Hier kannst du die eigentliche Kommunikation mit dem Arduino fortsetzen
  }
}

