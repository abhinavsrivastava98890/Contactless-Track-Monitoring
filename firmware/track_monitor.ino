// ============================================================
//  Contactless Track Monitoring Robot — sDx Legends
//  Inverthon 2.0 | Invertis University
//  Team: Abhinav Srivastava, Shekhar Singh, Tanishka Agarwal, Mohd. Junaid
// ============================================================

// -------------------- PIN DEFINITIONS ----------------------

// IR Sensors
#define IR_ALIGNMENT   34   // IR Sensor 1 — Track alignment (LEFT)
#define IR_CRACK       35   // IR Sensor 2 — Crack / Obstacle detection (RIGHT)

// BTS7960 Motor Driver — Left Motors
#define RPWM_LEFT      25   // Right PWM (Forward)
#define LPWM_LEFT      26   // Left PWM  (Backward)
#define R_EN_LEFT      27   // Right Enable
#define L_EN_LEFT      14   // Left Enable

// BTS7960 Motor Driver — Right Motors
#define RPWM_RIGHT     32   // Right PWM (Forward)
#define LPWM_RIGHT     33   // Left PWM  (Backward)
#define R_EN_RIGHT     18   // Right Enable
#define L_EN_RIGHT     19   // Left Enable

// Alert
#define BUZZER_PIN     23   // Buzzer
#define LED_PIN        22   // Fault LED

// -------------------- CONSTANTS ----------------------------

#define MOTOR_SPEED     180   // 0-255 — adjust as needed
#define IR_FAULT_VAL    LOW   // LOW = obstacle/crack detected (adjust per sensor)
#define IR_ALIGN_VAL    LOW   // LOW = off-track

// -----------------------------------------------------------

void setup() {
  Serial.begin(115200);
  Serial.println("sDx Legends — Track Monitor Booting...");

  // IR Sensors
  pinMode(IR_ALIGNMENT, INPUT);
  pinMode(IR_CRACK,     INPUT);

  // Motor Driver Enables
  pinMode(R_EN_LEFT,  OUTPUT); digitalWrite(R_EN_LEFT,  HIGH);
  pinMode(L_EN_LEFT,  OUTPUT); digitalWrite(L_EN_LEFT,  HIGH);
  pinMode(R_EN_RIGHT, OUTPUT); digitalWrite(R_EN_RIGHT, HIGH);
  pinMode(L_EN_RIGHT, OUTPUT); digitalWrite(L_EN_RIGHT, HIGH);

  // Motor PWM pins
  pinMode(RPWM_LEFT,  OUTPUT);
  pinMode(LPWM_LEFT,  OUTPUT);
  pinMode(RPWM_RIGHT, OUTPUT);
  pinMode(LPWM_RIGHT, OUTPUT);

  // Alert pins
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN,    OUTPUT);

  stopMotors();
  Serial.println("System Ready.");
}

// -----------------------------------------------------------

void loop() {
  int irAlign = digitalRead(IR_ALIGNMENT);
  int irCrack = digitalRead(IR_CRACK);

  // FAULT DETECTED — crack or obstacle
  if (irCrack == IR_FAULT_VAL) {
    stopMotors();
    triggerAlert();
    Serial.println("FAULT DETECTED — Crack / Obstacle!");
    delay(2000);  // Hold alert for 2 seconds
    return;
  }

  // OFF TRACK — realign
  if (irAlign == IR_ALIGN_VAL) {
    adjustAlignment();
    Serial.println(" Adjusting alignment...");
    return;
  }

  // ALL CLEAR — move forward
  moveForward();
  Serial.println(" Moving forward — track clear.");
  delay(100);
}

