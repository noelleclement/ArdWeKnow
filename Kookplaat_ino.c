int latchPin = 2;
int clockPin = 4;
int dataPin = 7;
int dig[8] = {127, 191, 223, 239, 247, 251, 253, 254};
int getal[8] = {0, 0, 0, 0, 0, 0, 0, 0};

boolean aan = false;
boolean lock = false;

int delay1 = 0;
int delay2 = 0;

int brightness[6] = {0, 0, 0, 0, 0, 0};

int led = 1;

unsigned long startCounter;
unsigned long stopCounter;

void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

    setupButtons();
    setupLeds();
    setupPiezo();

    Serial.begin(9600);
}

void setupButtons() {
    pinMode(16, INPUT_PULLUP);
    pinMode(17, INPUT_PULLUP);
    pinMode(14, INPUT_PULLUP);
    pinMode(15, INPUT_PULLUP);
    pinMode(18, INPUT_PULLUP);
    pinMode(19, INPUT_PULLUP);
}

void setupLeds() {
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void setupPiezo() {
    pinMode(8, OUTPUT);
}

void loop() {
    if (!lock) {
        if (digitalRead(19) == HIGH) {
            startCounter = millis();
        }

        if (digitalRead(19) == LOW) {
            playTone();
            stopCounter = startCounter + 5000;
            delay(100);

            Serial.println(stopCounter);
            Serial.println(millis());

            if (digitalRead(19) == HIGH) {
                if (millis() >= stopCounter) {
                    lock = true;
                }
            }
        }

        if (aan) {
            writeToDisp(getal[0], dig[0]);
            delay(2);
            writeToDisp(getal[1], dig[1]);
            delay(2);
            writeToDisp(getal[2], dig[2]);
            delay(2);
            writeToDisp(getal[3], dig[3]);
            delay(2);

            writeToDisp(getal[4], dig[4]);
            delay(2);
            writeToDisp(getal[5], dig[5]);
            delay(2);
            writeToDisp(getal[6], dig[6]);
            delay(2);
            writeToDisp(getal[7], dig[7]);
            delay(2);

            if (digitalRead(18) == LOW) {
                playTone();
                aan = false;
                delay(200);
            }

            switch (led) {
                case 1:
                    if (digitalRead(16) == LOW && brightness[0] != 0 && getal[0] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            brightness[0] -= 16;
                            getal[0]--;
                        }
                    }

                    if (digitalRead(17) == LOW && brightness[0] != 160 && getal[0] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            brightness[0] += 16;
                            getal[0]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH) {
                            led = 2;
                        }
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 8;
                        }
                    }

                    analogWrite(5, brightness[0]);
                break;

                case 2:
                    if (digitalRead(16) == LOW && brightness[1] != 0 && getal[1] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            brightness[1] -= 16;
                            getal[1]--;
                        }
                    }

                    if (digitalRead(17) == LOW && brightness[1] != 160 && getal[1] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            brightness[1] += 16;
                            getal[1]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH) {
                            led = 3;
                        }
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 1;
                        }
                    }

                    analogWrite(9, brightness[1]);
                break;

                case 3:
                    if (digitalRead(16) == LOW && brightness[2] != 0 && getal[2] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            brightness[2] -= 16;
                            getal[2]--;
                        }
                    }

                    if (digitalRead(17) == LOW && brightness[2] != 160 && getal[2] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            brightness[2] += 16;
                            getal[2]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH) {
                            led = 4;
                        }
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 2;
                        }
                    }

                    analogWrite(10, brightness[2]);
                break;

                case 4:
                    if (digitalRead(16) == LOW && brightness[3] != 0 && getal[3] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            brightness[3] -= 16;
                            getal[3]--;
                        }
                    }

                    if (digitalRead(17) == LOW && brightness[3] != 160 && getal[3] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            brightness[3] += 16;
                            getal[3]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH)
                            led = 5;
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 3;
                        }
                    }

                    analogWrite(11, brightness[3]);
                break;

                case 5:
                    if (digitalRead(16) == LOW && brightness[4] != 0 && getal[4] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            brightness[4] -= 16;
                            getal[4]--;
                        }
                    }

                    if (digitalRead(17) == LOW && brightness[4] != 160 && getal[4] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            brightness[4] += 16;
                            getal[4]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH) {
                            led = 6;
                        }
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 4;
                        }
                    }

                    analogWrite(3, brightness[4]);
                break;

                case 6:
                    if (digitalRead(16) == LOW && brightness[5] != 0 && getal[5] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            brightness[5] -= 16;
                            getal[5]--;
                        }
                    }

                    if (digitalRead(17) == LOW && brightness[5] != 160 && getal[5] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            brightness[5] += 16;
                            getal[5]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH) {
                            led = 7;
                        }
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 5;
                        }
                    }

                    analogWrite(6, brightness[5]);
                break;

                case 7:
                    if (digitalRead(16) == LOW && delay1 != 0 && getal[6] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            delay1 -= 1;
                            getal[6]--;
                        }
                    }

                    if (digitalRead(17) == LOW && delay1 != 10 && getal[6] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            delay1 += 1;
                            getal[6]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH) {
                            led = 8;
                        }
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 6;
                        }
                    }
                break;

                case 8:
                    if (digitalRead(16) == LOW && delay2 != 0 && getal[7] != 0) {
                        playTone();
                        delay(10);

                        if (digitalRead(16) == HIGH) {
                            delay2 -= 1;
                            getal[7]--;
                        }
                    }

                    if (digitalRead(17) == LOW && delay2 != 10 && getal[7] != 9) {
                        playTone();
                        delay(10);

                        if (digitalRead(17) == HIGH) {
                            delay2 += 1;
                            getal[7]++;
                        }
                    }

                    if (digitalRead(15) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(15) == HIGH) {
                            led = 1;
                        }
                    }

                    if (digitalRead(14) == LOW) {
                        playTone();
                        delay(10);

                        if (digitalRead(14) == HIGH) {
                            led = 7;
                        }
                    }
                break;
            }

            digitalWrite(12, HIGH);
            delay(delay1);
            digitalWrite(12, LOW);
            delay(5);

            digitalWrite(13, HIGH);
            delay(delay2);
            digitalWrite(13, LOW);
            delay(5);

            //delay(200);
        } else {
            analogWrite(5, 0);
            analogWrite(9, 0);
            analogWrite(10, 0);
            analogWrite(11, 0);
            analogWrite(3, 0);
            analogWrite(6, 0);

            getal[0] = 0;
            getal[1] = 0;
            getal[2] = 0;
            getal[3] = 0;
            getal[4] = 0;
            getal[5] = 0;
            getal[6] = 0;
            getal[7] = 0;

            if (digitalRead(18) == LOW) {
                playTone();
                aan = true;
            }

            delay(200);
        }
    } else {
        if (digitalRead(19) == HIGH) {
            startCounter = millis();
        }

        if (digitalRead(19) == LOW) {
            playTone();
            stopCounter = startCounter + 5000;
            delay(100);

            Serial.println(stopCounter);
            Serial.println(millis());

            if (digitalRead(19) == HIGH) {
                if (millis() >= stopCounter) {
                    lock = false;
                }
            }
        }

        Serial.println(aan);
        Serial.println(lock);
        //Serial.println(brightness[0]);
        //Serial.println(brightness[1]);
        //Serial.println(brightness[2]);
        //Serial.println(brightness[3]);

        //Serial.println(brightness[4]);
        //Serial.println(brightness[5]);
        //Serial.println(delay1);
        //Serial.println(delay2);

        Serial.println(led);
    }
}

void playTone() {
    tone(8, 440, 200);
}

void writeToDisp (int number, int digit) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, digit); // Digit power

    switch (number) {
        case 0:
            shiftOut(dataPin, clockPin, MSBFIRST, 215);  // The number 0 is shown
        break;

        case 1:
            shiftOut(dataPin, clockPin, MSBFIRST, 20);   // The number 1 is shown
        break;

        case 2:
            shiftOut(dataPin, clockPin, MSBFIRST, 205);  // The number 2 is shown
        break;

        case 3:
            shiftOut(dataPin, clockPin, MSBFIRST, 93);  // The number 3 is shown
        break;

        case 4:
            shiftOut(dataPin, clockPin, MSBFIRST, 30);  // The number 4 is shown
        break;

        case 5:
            shiftOut(dataPin, clockPin, MSBFIRST, 91);  // The number 5 is shown
        break;

        case 6:
            shiftOut(dataPin, clockPin, MSBFIRST, 251); // The number 6 is shown
        break;

        case 7:
            shiftOut(dataPin, clockPin, MSBFIRST, 21);  // The number 7 is shown
        break;

        case 8:
            shiftOut(dataPin, clockPin, MSBFIRST, 223); // The number 8 is shown
        break;

        case 9:
            shiftOut(dataPin, clockPin, MSBFIRST, 127); // The number 9 is shown
    }

    digitalWrite(latchPin, HIGH);
}