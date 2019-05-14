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
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

#### Schemat elektroniczny
![](./schematic.png "Schemat elektroniczny")

#### Schemat PCB
![](./PCB.png "Schemat PCB")