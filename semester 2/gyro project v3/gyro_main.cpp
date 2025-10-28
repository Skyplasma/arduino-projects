#include "Wire.h"
#include "Mouse.h"
// sup
//pinout
const int MPU_ADDR = 0x68;
const int Jstick_X = A0;
const int Jstick_Y = A1;
const int Jstick_button = 2;


//gyro variables
int16_t accle_x, accle_y, accle_z;
int16_t gyro_x, gyro_y, gyro_z;
int16_t temperature;

//sensitivity values
const int register_value = 6000;
const int drag_sens = 1250;
const int gyro_sens = 16000;
const int gyro_x_calibrate = 650;
const int grav_calibrate = 15000;
int Left_Measure = 0;
int Right_Measure = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial){};
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Mouse.begin();
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 7 * 2, true);

  accle_x = Wire.read() << 8 | Wire.read();
  accle_y = Wire.read() << 8 | Wire.read();
  accle_z = Wire.read() << 8 | Wire.read();
  temperature = Wire.read() << 8 | Wire.read();
  gyro_x = Wire.read() << 8 | Wire.read();
  gyro_y = Wire.read() << 8 | Wire.read();
  gyro_z = Wire.read() << 8 | Wire.read();

  Serial.print("aX = ");
  Serial.print(accle_x);
  Serial.print(" | aY = ");
  Serial.print(accle_y);
  Serial.print(" | aZ = ");
  Serial.print(accle_z);
  Serial.print(" | tm = ");
  Serial.print(Total_Movement());
  Serial.print(" | gX = ");
  Serial.print(gyro_x);
  Serial.print(" | gY = ");
  Serial.print(gyro_y);
  Serial.print(" | gZ = ");
  Serial.print(gyro_z);
  Serial.println();
  Serial.print(Left_Measure);
  Serial.print("   |   ");
  Serial.println(Right_Measure);
  delay(10);

  Mouse_Move();
  Mouse_Click();
  Measure();
}


int Total_Movement() {
  int i = (abs(accle_y) + abs(accle_z));
  return i;
}

void Mouse_Move() {
  if (Total_Movement() >= register_value) {
    Mouse.move((accle_y / drag_sens), (accle_z / drag_sens));
  };
}

void Measure() {
  if ((gyro_x + gyro_x_calibrate) < -16384) {
    Left_Measure = Left_Measure + gyro_x + gyro_x_calibrate;
  }
  if ((gyro_x + gyro_x_calibrate) > 16384) {
    Right_Measure = Right_Measure + gyro_x + gyro_x_calibrate;
  }
}

void Mouse_Click() {
  if ((gyro_x + gyro_x_calibrate  > 0) && (abs(gyro_x + gyro_x_calibrate) > (gyro_sens + abs(Right_Measure)))) {
    Mouse.click();
    Right_Measure = 0;
  }
  if ((gyro_x + gyro_x_calibrate < 0) && (abs(gyro_x + gyro_x_calibrate) > (gyro_sens + abs(Left_Measure)))) {
    Mouse.click(MOUSE_RIGHT);
    Left_Measure = 0;
  }
}
