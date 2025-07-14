#define STEP 26
#define DIR 27
#define SERVO 22
#define BUT1 16
#define BUT2 19

#define STRING_LENGTH 150 // in mm
#define SPOOL_DIA 10 // in mm
#define STEPS_PER_ROTATION 200
#define MICROSTEPS 4




#define SPOOL_CIRCUMFERENCE SPOOL_DIA * 3.14

int bstate1 = 0; // button state 1
int bstate2 = 0; // button state 2
int sstate = 0; // string state
int iswound = 0;
int direction = 0; // direction




void setup() {
    pinMode(STEP, OUTPUT);
    pinMode(DIR, OUTPUT);
    pinMode(SERVO, OUTPUT);
    pinMode(BUT1, INPUT);
    pinMode(BUT2, INPUT);

    attachInterrupt(BUT1, but_press1, CHANGE);
    attachInterrupt(BUT2, but_press2, CHANGE);
}

void loop() {
    delay(1);
}

void step(int distance, int direction) { // direction: 0 for left, 1 for right
    digitalWrite(DIR, direction);
    float angle = (distance / SPOOL_CIRCUMFERENCE) * 360.0; // in degrees
    int steps = ((STEPS_PER_ROTATION * MICROSTEPS) / 360) * angle; // steps to wind distance of string
    for(int x = 0; x++; x < (steps)) {
        digitalWrite(STEP, HIGH);
        delayMicroseconds(400);
        digitalWrite(STEP, LOW);
        delayMicroseconds(400);
    }
    servo(0);
    digitalWrite(DIR, !direction);
    float angle = (distance / SPOOL_CIRCUMFERENCE) * 360.0; // in degrees
    int steps = ((STEPS_PER_ROTATION * MICROSTEPS) / 360) * angle; // steps to wind distance of string
    for(int x = 0; x++; x < (steps)) {
        digitalWrite(STEP, HIGH);
        delayMicroseconds(400);
        digitalWrite(STEP, LOW);
        delayMicroseconds(400);
    }
}


void servo(int direction) {
    if(direction == 0) {
        digitalWrite(SERVO, HIGH); // move servo to right
        delayMicroseconds(1000);
        digitalWrite(SERVO, LOW);
        delayMicroseconds(20000 - 1000); // 20ms period for servo
    } else if(direction == 1) {
        digitalWrite(SERVO, HIGH); // move servo to right
        delayMicroseconds(1300);
        digitalWrite(SERVO, LOW);
        delayMicroseconds(20000 - 1300); // 20ms period for servo
    }

}

void but_press1() {
    if(digitalRead(BUT1) == LOW) {
        Serial.println("Button 1 pressed");
    }
    if(digitalRead(BUT2) == HIGH) {
        if(sstate)
    }
}

void but_press2() {
    if(digitalRead(BUT2) == LOW) {
        delay(1);
    }
    if(digitalRead(BUT2) == HIGH) {
        if(sstate == 1) {
            delay(1);
        }
        if(sstate == 0) {
            servo(1);
        }
    }
}