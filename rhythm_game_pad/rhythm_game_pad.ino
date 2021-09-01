#include "Keyboard.h"

const byte xAxis = A1;
const byte yAxis = A0;
const byte dAxis = 12;
const short button1 = 2;
const short button2 = 3;
const short button3 = 4;
const short button4 = 5;
const short button5 = 6;
const short button6 = 7;
const short button7 = 8;
const short button8 = 9;
const short button9 = 10;
const short button10 = 11;
const char bt1 = 'n';
const char bt2 = 'l';
const char bt3 = 'k';
const char bt4 = 'j';
const char bt5 = KEY_RIGHT_SHIFT;
const char bt6 = KEY_LEFT_SHIFT;
const char bt7 = 'd';
const char bt8 = 's';
const char bt9 = 'a';
const char bt10 = KEY_ESC;
const char xyReturn = KEY_RETURN;
const char xyLeft = KEY_LEFT_ARROW;
const char xyRight = KEY_RIGHT_ARROW;
const char xyUp = KEY_UP_ARROW;
const char xyDown = KEY_DOWN_ARROW;

void setup() {                                                                                                                                                                                             
  Keyboard.begin();
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);
  pinMode(button10, INPUT_PULLUP);
  pinMode(dAxis, INPUT_PULLUP);
}

void loop() {
  int AXIS_X = analogRead(xAxis);
  int AXIS_Y = analogRead(yAxis);
  joyStick(AXIS_X, xyLeft, xyRight);
  joyStick(AXIS_Y, xyUp, xyDown);
  key(button1, bt1);
  key(button2, bt2);
  key(button3, bt3);
  key(button4, bt4);
  key(button5, bt5);
  key(button6, bt6);
  key(button7, bt7);
  key(button8, bt8);
  key(button9, bt9);
  key(button10, bt10);
}

void joyStick(int joyXY, char direc1, char direc2){
    int AXIS_D = digitalRead(dAxis);
    //조이스틱 눌림 
    if(AXIS_D == 0){
       Keyboard.press(xyReturn);
    }
    else{
       Keyboard.release(xyReturn);
    }
    
    //x, y축 방향값
    if(joyXY<=150){
       Keyboard.press(direc1);
    }
    else if(joyXY>=850){
       Keyboard.press(direc2);
    }
    else{
      Keyboard.release(direc1);
      Keyboard.release(direc2);  
    }
}

void key(short btn, char selct){
  if(!digitalRead(btn)){
    Keyboard.press(selct); //키보드가 눌렸다.
  } else{
    Keyboard.release(selct); //키보드가 떨어졌다.
  }
}
