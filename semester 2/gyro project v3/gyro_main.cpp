#include "Wire.h"
#include "Mouse.h"

//pinout
const int MPU_ADDR = 0x68;
const int Jstick_X = A0;
const int Jstick_Y = A1;
const int Jstick_button = 2;


//gyro variables
int16_t accle_x, accle_y,  accle_z;
int16_t gyro_x, gyro_y, gyro_z;
int16_t temperature;

char tmp_str[7]

char* convert_int16_to_str(int16_t i) {
    sprintf(tmp_str, "%6d", i);
    return tmp_str;
}

void setup() {
    Serial.begin(9600);
    Wire.begin();
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x68);
    Wire.write(0);
    Wire.endTransmission(true);
}

void loop() {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR,7*2, true);

    accle_x = Wire.read()<<8 | Wire.read();
    accle_y = Wire.read()<<8 | Wire.read();
    accle_z = Wire.read()<<8 | Wire.read();
    temperature = Wire.read()<<8 | Wire.read();
    gyro_x = Wire.read()<<8 | Wire.read();
    gyro_y = Wire.read()<<8 | Wire.read();
    gyro_z = Wire.read()<<8 | Wire.read();

    Serial.print("aX = "); Serial.print(convert_int16_to_str(accle_x));
    Serial.print(" | aY = "); Serial.print(convert_int16_to_str(accle_y));
    Serial.print(" | aZ = "); Serial.print(convert_int16_to_str(accle_z));
    Serial.print(" | tmp = "); Serial.print(convert_int16_to_str(temperature));
    Serial.print(" | gX = "); Serial.print(convert_int16_to_str(gyro_x));
    Serial.print(" | gY = "); Serial.print(convert_int16_to_str(gyro_y));
    Serial.print(" | gZ = "); Serial.print(convert_int16_to_str(gyro_z));
    Serial.println();
    delay(1000);
}

void mpu6050read() {
    
}