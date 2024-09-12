// 1

using System.IO.Ports;

class Program
{
    static void Main(string[] args)
    {
        SerialPort port = new SerialPort("COM3", 1200);  // COM3 und 1200 Baudrate
        port.Open();
        port.WriteLine("SWITCH_TO_9600");
        
        // Kurze Verzögerung, um Arduino Zeit zu geben, die Baudrate zu wechseln
        System.Threading.Thread.Sleep(100);

        // Schließe den Port und öffne ihn mit der neuen Baudrate
        port.Close();
        port.BaudRate = 9600;
        port.Open();

        // Hier kannst du mit dem Arduino mit 9600 Baudrate weiter kommunizieren
        port.WriteLine("Hello from 9600 Baudrate!");

        port.Close();
    }
}

// 2

using System.IO.Ports;

class Program
{
    static void Main(string[] args)
    {
        SerialPort port = new SerialPort("COM3", 1200);
        port.Open();
        port.WriteLine("SWITCH_TO_9600");

        // Warte auf Bestätigung von Arduino
        string response = port.ReadLine();
        if (response == "ACK_1200")
        {
            // Schließe den Port und schalte auf 9600 um
            port.Close();
            port.BaudRate = 9600;
            port.Open();

            // Warte auf Bestätigung nach Umschaltung auf 9600 Baud
            response = port.ReadLine();
            if (response == "ACK_9600")
            {
                // Jetzt mit 9600 Baudrate kommunizieren
                port.WriteLine("Hello from 9600 Baud!");
            }
        }

        port.Close();
    }
}
