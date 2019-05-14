---
title: Sterowanie LED metodą PWM
author: Wiktor Buliński
date: 15 maja 2019
---

## Sterowanie LED metodą PWM
### Zasada działania:
PWM (ang. **P**ulse **W**idth **M**odulation) jest określeniem sygnału cyfrowego.
Najczęściej stosowany jest do sterowania szybkością serwo silnika, kontroli jasności oświetlenia czy w zasilaniu urządzeń. Sygnał ten podobny jest do sygnału
prostąkątnego. Przy stałej częstotliwości i amplitudzie generowane są impulsy
trwające pewną część okresu, nazywamy to wpółczynnikiem wypełnienia.  

Kontrolując współczynnik wypełnienienia wpływamy na średnią wartość napięcia
tym samym zmieniając moc wyjściową. Wynika to ze wzrou P = U·I gdzie pod
wartość napięcia podstawiamy jej średnią w okresie.

![](./pwm-duty.png "Przebiegi PWM o różnym wypełnieniu")

#### Sterowanie LED

Płytka badawcza posiada diodę RGB, której moc świecenia dla każdego koloru sterowana jest metodą PWM. Regulując odpowiednio wartość wypełnienia dla poszczególnych kolorów podstawowych; jesteśmy w stanie otrzymać dowolny kolor świecenia (paleta RGB posiada 16 777 216 teoretycznych kolorów).  
Regulacja odbywa sie przez podanie sygnału analogowego do mikrokontrolera który po przetworzeniu sygnału reaguje zmieniając współczynnik wypełnienia dla odpowiedniego koloru diody.

### Dokumentacja techniczna

#### Spis elementów elektronicznych

- Jednostka logiczna - **mikrokontroler Atmega328P-AU** - obudowa TQFP 32 piny
- **Dioda luminescencyjna RGB** o wspólnej anodzie (wyk. TJ-L5FYTXHMCYLCRGB-A5) - obudowa THT
- Tranzystor przełączający - **MOSFET z kanałem typu N** (wyk. STN3NF06L) - obudowa SOT-223 (x3)
- **Rezystor** regulujący napięcie diody **100Ω** - obudowa SMD1206
- **Rezystor** regulujący napięcie diody **150Ω** - obudowa SMD1206
- Elementy filtrujące zasilanie:
  - **Kondensator ceramiczny 100nF** - obudowa SMD1206 (x3)
  - **Dławik 10μH obudowa** - obudowa SMD1206
  - **Rezystor** podciągający napięcie pinu reset **10kΩ** - obudowa SMD1206
- Gniazda i wyprowadzenia:
  - **Gniazdo zasilające DC powerjack 2.5mm** - obudowa SMD
  - **Trój-pinowe wyprowadzenie na analogowy sygnał sterowania** - obudowa THT, raster 2.54mm (x3)
  - **Sześcio-pinowe Wyprowadzenie do programowania układu** - obudowa THT, raster 2.54mm

#### Program wykonawczy

<!-- TODO change code to real one -->

```C
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
```

#### Schemat elektroniczny
![](./schematic.png "Schemat elektroniczny")

#### Schemat PCB
![](./PCB.png "Schemat PCB")