/* Variables de estado */
bool led_status = false;
bool buzzer_status = false;

/* Pines */
int const m1_p1 = 5; /* Pines Motor 1 */
int const m1_p2 = 6;

int const m2_p1 = 9; /* Pines Motor 2 */
int const m2_p2 = 10;

int const buzzer_pin = 12;
int const led_pin = 13;

/* configuración */
int speed = 255; /* Velocidad */
char action = '0';

void setup() {
  Serial.begin(9600);
  pinMode(m1_p1, OUTPUT);
  pinMode(m1_p2, OUTPUT);
  pinMode(m2_p1, OUTPUT);
  pinMode(m2_p2, OUTPUT);

  pinMode(buzzer_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    action = Serial.read();
    Serial.println(action);
  }

  switch(action){
    case 'F' : engineAction(speed, 0, speed, 0); break; /* Adelante */
    case 'B' : engineAction(0, speed, 0, speed); break; /* Atrás */
    case 'L' : engineAction(0, speed, speed, 0); break; /* Izquierda */
    case 'R' : engineAction(speed, 0, 0, speed); break; /* Derecha */
    case 'v' :
    case 'V' : 
      digitalWrite(buzzer_pin, !buzzer_status); 
      buzzer_status = !buzzer_status; break; /* Encender o apagar luces */
    case 'w' :
    case 'W' : 
      digitalWrite(led_pin, !led_status);
      led_status = !led_status; break; /* Encender o apagar bocina */
    default : engineAction(0, 0, 0, 0);
  }
}

void engineAction(int v1, int v2, int v3, int v4){
  analogWrite(m1_p1, v1);
  analogWrite(m1_p2, v2);
  analogWrite(m2_p1, v3);
  analogWrite(m2_p2, v4);
}