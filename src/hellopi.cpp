#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
using namespace std;

int main() {
  cout << "Started" << endl;

  if (wiringPiSetup() < 0) {
    cout << "setup wiring pi failed" << endl;
    return 1;
  }

  int c;
  int ledPin = 29;
  pinMode(ledPin, OUTPUT);

  for (int i = 0; i < 10; i++) {
    cout << "Blinking" << i << endl;
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }

  cout << "Finished" << endl;

  return 0;
}