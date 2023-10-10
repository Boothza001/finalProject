
  /*
 * 
 * This code is basic usage MPU-6050 Accelerometer and Gyroscope
 * 
 * This code displays :

 * -AAngle X, Angle Y,Angle Z,
 * 
 * Library and code have been taken from:
 * https://github.com/tockn/MPU6050_tockn
 * 
 * Updated by Ahmad Shamshiri on July 03, 2018 in Ajax, Ontario, Canada
 * for Robojax.com
 * Get this code from Robojax.com
 * Watch video instruction for this code at:https://youtu.be/uhh7ik02aDc
 * 
 */
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 1000){
    
    Serial.println("");
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("	                                                             angleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("	                                                             angleZ : ");Serial.println(mpu6050.getAngleZ());
    Serial.println("");
    timer = millis();
    
  }

} 