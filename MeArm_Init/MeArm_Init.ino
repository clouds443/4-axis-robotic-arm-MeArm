/*
MeArm舵机初始化调整程序 
*/

#include <Servo.h> 
 
Servo base, rArm, fArm, claw ;  //建立4个舵机对象
 
void setup() 
{ 
  base.attach(11);     // base 伺服舵机连接引脚11 舵机代号'b'
  rArm.attach(10);     // rArm 伺服舵机连接引脚10 舵机代号'r'
  fArm.attach(9);      // fArm 伺服舵机连接引脚9  舵机代号'f'
  claw.attach(6);      // claw 伺服舵机连接引脚6  舵机代号'c'
  Serial.begin(9600);
} 
void loop() 
{ 
  base.write(90); // 将base（底盘）舵机设置为初始位置
  delay(100);
  rArm.write(90); // 将rArm（后臂）舵机设置为初始位置
  delay(100);
  fArm.write(90); // 将fArm（前臂）舵机设置为初始位置
  delay(100);
  claw.write(90); // 将claw（钳子）舵机设置为初始位置
  delay(3000); 
} 
