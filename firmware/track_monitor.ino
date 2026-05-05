// ============================================================
//  Contactless Track Monitoring Robot — sDx Legends
//  Inverthon 2.0 | Invertis University
//  Team: Abhinav Srivastava, Shekhar Singh, Tanishka Agarwal, Mohd. Junaid
// ============================================================

// -------------------- IR SENSORS ---------------------------
#define IR_LEFT_RAIL   34   // IR Sensor 1 — Left rail monitor
#define IR_RIGHT_RAIL  35   // IR Sensor 2 — Right rail monitor

// -------------------- MOTOR DRIVER LEFT (BTS7960 #1) -------
#define RPWM_LEFT      25
#define LPWM_LEFT      26
#define R_EN_LEFT      27
#define L_EN_LEFT      14

// -------------------- MOTOR DRIVER RIGHT (BTS7960 #2) ------
#define RPWM_RIGHT     32
#define LPWM_RIGHT     33
#define R_EN_RIGHT     18
#define L_EN_RIGHT     19

// -------------------- ALERTS --------------------------------
#define LED_PIN        22
#define BUZZER_PIN     23

// -------------------- MOTOR SETTINGS -----------------------
#define MOTOR_SPEED    180   // 0-255
#define IR_FAULT_VAL   LOW   // LOW = rail not detected (crack/gap)

// -----------------------------------------------------------

void setup() {
  Serial.begin(115200);
  Serial.println("sDx Legends — Track Monitor Booting...");

  pinMode(IR_LEFT_RAIL,  INPUT);
  pinMode(IR_RIGHT_RAIL, INPUT);

  pinMode(R_EN_LEFT,  OUTPUT); digitalWrite(R_EN_LEFT,  HIGH);
  pinMode(L_EN_LEFT,  OUTPUT); digitalWrite(L_EN_LEFT,  HIGH);
  pinMode(R_EN_RIGHT, OUTPUT); digitalWrite(R_EN_RIGHT, HIGH);
  pinMode(L_EN_RIGHT, OUTPUT); digitalWrite(L_EN_RIGHT, HIGH);

  pinMode(RPWM_LEFT,  OUTPUT);
  pinMode(LPWM_LEFT,  OUTPUT);
  pinMode(RPWM_RIGHT, OUTPUT);
  pinMode(LPWM_RIGHT, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN,    OUTPUT);

  stopMotors();
  Serial.println("System Ready. Monitoring both rails...");
}

// -----------------------------------------------------------

void loop() {
  int irLeft  = digitalRead(IR_LEFT_RAIL);
  int irRight = digitalRead(IR_RIGHT_RAIL);

  if (irLeft == IR_FAULT_VAL || irRight == IR_FAULT_VAL) {
    stopMotors();
    triggerAlert();

    if (irLeft == IR_FAULT_VAL && irRight == IR_FAULT_VAL)
      Serial.println("FAULT — Both rails missing!");
    else if (irLeft == IR_FAULT_VAL)
      Serial.println("FAULT — Left rail crack/gap detected!");
    else
      Serial.println("FAULT — Right rail crack/gap detected!");

    delay(2000);
    return;
  }

  moveForward();
  Serial.println("Both rails OK — moving forward.");
  delay(100);
}

// -----------------------------------------------------------
//  MOTOR CONTROL
// -----------------------------------------------------------

void moveForward() {
  analogWrite(RPWM_LEFT,  MOTOR_SPEED);
  analogWrite(LPWM_LEFT,  0);
  analogWrite(RPWM_RIGHT, MOTOR_SPEED);
  analogWrite(LPWM_RIGHT, 0);
}

void stopMotors() {
  analogWrite(RPWM_LEFT,  0);
  analogWrite(LPWM_LEFT,  0);
  analogWrite(RPWM_RIGHT, 0);
  analogWrite(LPWM_RIGHT, 0);
}

// -----------------------------------------------------------
//  ALERT
// -----------------------------------------------------------

void triggerAlert() {
  digitalWrite(LED_PIN,    HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN,    LOW);
}

