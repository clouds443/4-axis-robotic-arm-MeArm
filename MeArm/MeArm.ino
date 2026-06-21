#include <Servo.h>                  //引入舵机驱动库
Servo base, fArm, rArm, claw ;      //创建4个舵机对象：底座、前大臂、后小臂、夹爪

// 各舵机角度限位常量，防止堵转
const int baseMin = 0;
const int baseMax = 180;
const int rArmMin = 45;
const int rArmMax = 180;
const int fArmMin = 35;
const int fArmMax = 120;
const int clawMin = 25;
const int clawMax = 100;

int DSD = 15; //Default Servo Delay舵机步进延时，数值越大转动越慢

// 判断是否为空白字符（空格、Tab、回车、换行），避免串口监视器自带的结束符被当作命令误报
bool isWhitespace(char c) {
  return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

void setup() {
  Serial.begin(9600); // 初始化串口波特率

  base.attach(11);    // base底座舵机接引脚11 指令代号'b'
  delay(200);          //上电防抖等待
  rArm.attach(10);    // rArm后小臂舵机接引脚10 指令代号'r'
  delay(200);
  fArm.attach(9);     // fArm前大臂舵机接引脚9 指令代号'f'
  delay(200);
  claw.attach(6);     // claw夹爪舵机接引脚6 指令代号'c'
  delay(200);

  // 上电所有舵机回归中位90°
  base.write(90);
  delay(10);
  fArm.write(90);
  delay(10);
  rArm.write(90);
  delay(10);
  claw.write(90);
  delay(10);
}

void loop() {
  if (Serial.available() > 0) {
    char serialCmd = Serial.read();
    armDataCmd(serialCmd);
  }
}

// 串口指令解析总函数
void armDataCmd(char serialCmd) {
  //指令示例：b45 底座转到45°；发送o查询所有舵机角度
  // 过滤空白字符：避免串口监视器发送的换行/回车被当作命令，从而产生 "Unknown Command" 误报
  if (isWhitespace(serialCmd)) return;

  if (serialCmd == 'b' || serialCmd == 'c' || serialCmd == 'f' || serialCmd == 'r') {
    int servoData = Serial.parseInt();
    servoCmd(serialCmd, servoData, DSD);
  } else {
    switch(serialCmd) {
      case 'o':  // 指令o：查询并打印所有舵机当前角度
        reportStatus();
        break;
      default:   // 未知指令反馈
        Serial.println("Unknown Command.");
    }
  }
}

// 舵机运动控制函数：实现限位校验+平缓分步转动
void servoCmd(char servoName, int toPos, int servoDelay) {
  Servo servo2go;
  // 打印收到的运动指令信息
  Serial.println("");
  Serial.print("+Command: Servo ");
  Serial.print(servoName);
  Serial.print(" to ");
  Serial.print(toPos);
  Serial.print(" at servoDelay value ");
  Serial.print(servoDelay);
  Serial.println(".");
  Serial.println("");

  int fromPos; // 存储舵机当前起始角度
  switch(servoName){
    case 'b':
      if(toPos >= baseMin && toPos <= baseMax){
        servo2go = base;
        fromPos = base.read();
        break;
      } else {
        Serial.println("+Warning: Base Servo Value Out Of Limit!");
        return;
      }

    case 'c':
      if(toPos >= clawMin && toPos <= clawMax){
        servo2go = claw;
        fromPos = claw.read();
        break;
      } else {
        Serial.println("+Warning: Claw Servo Value Out Of Limit!");
        return;
      }

    case 'f':
      if(toPos >= fArmMin && toPos <= fArmMax){
        servo2go = fArm;
        fromPos = fArm.read();
        break;
      } else {
        Serial.println("+Warning: fArm Servo Value Out Of Limit!");
        return;
      }

    case 'r':
      if(toPos >= rArmMin && toPos <= rArmMax){
        servo2go = rArm;
        fromPos = rArm.read();
        break;
      } else {
        Serial.println("+Warning: rArm Servo Value Out Of Limit!");
        return;
      }
  }

  // 舵机平缓分步转动
  if (fromPos <= toPos) {
    for (int i=fromPos; i<=toPos; i++) {
      servo2go.write(i);
      delay(servoDelay);
    }
  } else {
    for (int i=fromPos; i>=toPos; i--) {
      servo2go.write(i);
      delay(servoDelay);
    }
  }
}

// 打印所有舵机当前角度状态
void reportStatus() {
  Serial.println("");
  Serial.println("");
  Serial.println("+ Robot-Arm Status Report +");
  Serial.print("Claw Position: "); Serial.println(claw.read());
  Serial.print("Base Position: "); Serial.println(base.read());
  Serial.print("Rear Arm Position:"); Serial.println(rArm.read());
  Serial.print("Front Arm Position:"); Serial.println(fArm.read());
  Serial.println("++++++++++++++++++++++++++");
  Serial.println("");
}