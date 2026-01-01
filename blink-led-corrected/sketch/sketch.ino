// SPDX-FileCopyrightText: Copyright (C) 2025 ARDUINO SA <http://www.arduino.cc>
//
// SPDX-License-Identifier: MPL-2.0

#include "Arduino_RouterBridge.h"

void setup() {
    pinMode(LED4_G, OUTPUT);
    pinMode(LED3_R,OUTPUT);
    digitalWrite(LED4_G, HIGH);
    digitalWrite(LED3_R, HIGH);

    Bridge.begin();
    Bridge.provide("set_led_state", set_led_state);
}

void loop() {
}

void set_led_state(bool state) {
    // LOW state means LED is ON
    digitalWrite(LED4_G, state ? LOW : HIGH);
    digitalWrite(LED3_R, state ? HIGH : LOW);
}