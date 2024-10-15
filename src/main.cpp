#include <Arduino.h>
#include "utils.h"

const int LED = 48;

bool ledMode = true;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello World");

  printBoardInfo();

  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledMode);
}

void loop() {
  delay(1000);
  ledMode = !ledMode;  // 切换 LED 状态
  digitalWrite(LED, ledMode);
}