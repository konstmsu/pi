#include <iostream>
#include <signal.h>
#include <wiringPi.h>

using namespace std;

static volatile sig_atomic_t sigint_received = false;

int main() {
  cout << "Started!" << endl;
  signal(SIGINT, [](int) { sigint_received = true; });

  if (wiringPiSetup() < 0) {
    cout << "Wiring PI setup failed" << endl;
    return 1;
  }

  int ledPin = 8;
  pinMode(ledPin, OUTPUT);

  for (int i = 0; i < 100; i++) {
    if (sigint_received)
      break;

    cout << "Blinking " << i << endl;
    digitalWrite(ledPin, LOW);
    delay(50);
    digitalWrite(ledPin, HIGH);
    delay(100);
  }

  cout << "Finished" << endl;

  return 0;
}