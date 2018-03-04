/*

 */

int sensorPin = A0;    // select the input pin for the potentiometer
int redPin = 9;      // select the pin for the LED
int greenPin = 10;      // select the pin for the LED
int bluePin = 11;      // select the pin for the LED
int inputPin = 7;               // choose the input pin (for PIR sensor)

int sensorValue = 0;  // variable to store the value coming from the sensor
int pirState = LOW;             // we start, assuming no motion detected

void setup() {
  Serial.begin(115200);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(inputPin, INPUT);
 
}

void loop() {

  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }

  if (pirState == LOW) {
    analogWrite(redPin,  0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(100);
    return;
  }
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  double h = sensorValue / 1024.0L;
  double s = 0.3L;
  double l = 0.5L;

  double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
  double p = 2 * l - q;
  double r, g, b;

  r = hue2rgb(p, q, h + 1/3.0);
  g = hue2rgb(p, q, h);
  b = hue2rgb(p, q, h - 1/3.0);

  String msg = "S = ";
  msg = msg + sensorValue + ": h = " + h + ", p = " + p + ", q = " + q + ", r = " + r + ", g = " + g + ", b = " + b; 
  Serial.println(msg);
  analogWrite(redPin,  r * 255);
  analogWrite(greenPin, g * 255);
  analogWrite(bluePin, b * 255);
  delay(100);
}

double hue2rgb(double p, double q, double t) {
    if(t < 0) t += 1;
    if(t > 1) t -= 1;
    if(t < 1/6.0) return p + (q - p) * 6 * t;
    if(t < 1/2.0) return q;
    if(t < 2/3.0) return p + (q - p) * (2/3.0 - t) * 6;
    return p;
}
