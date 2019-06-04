// Definicja pinów wyjściowych PWM
const int OutputR = 9;
const int OutputG = 5;
const int OutputB = 6;

// Definicja analogowych pinów wejściowych
const int InputR = A0;
const int InputG = A1;
const int InputB = A2;

// Wartości kolorów
int valueR = 0;
int valueG = 0;
int valueB = 0;

// Ustawnienie pinów wyjściowych na odpowiedni tryb
void setup() {
  pinMode(OutputR, OUTPUT);
  pinMode(OutputG, OUTPUT);
  pinMode(OutputB, OUTPUT);
}

void loop() {
  // Sprawdzanie wartości wejść analogowych i mapowanie ich na wartość 0-255 (PWM gdzie 255 odpowiada 100% wypełnieniu)
  valueR = map(analogRead(InputR), 0, 1023, 0, 255);
  valueG = map(analogRead(InputG), 0, 1023, 0, 255);
  valueB = map(analogRead(InputB), 0, 1023, 0, 255);
  
  // Ustawianie koloru na podstawie wartości analogowych
  setColor(valueR, valueG, valueB);
}

void setColor(int red, int green, int blue) {
  // Ustawianie odpowiedniego współczynnika wypełnienia dla każdego pinu
  analogWrite(OutputR, red);
  analogWrite(OutputG, green);
  analogWrite(OutputB, blue);
}
