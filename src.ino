const int R = 9;
const int G = 5;
const int B = 6;
//const int AR = A0;
//int ARValue = 1;

void setup() {
  pinMode(R, OUTPUT); //RED
  pinMode(G, OUTPUT); //GREEN
  pinMode(B, OUTPUT); //BLUE
  setColourRgb(0,0,0);
}

void loop() {
//  ARValue = map(analogRead(AR), 0, 1023, 0, 255);

  
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(10);
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue);
 }
