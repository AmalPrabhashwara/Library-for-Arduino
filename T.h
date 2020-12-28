#ifndef T_h
#define T_h

#include "Arduino.h"
//#include<string.h>

class T
{
  public:
    void storeInt(int x);
    void storeFloat(float x);
    int readInt(int x);
    float readFloat(int x);
    void clearFloat();
    void clearInt();
    void storeChar(char x);
    char readChar(int n);
    String readstring(int n);
    void storeString(char x[]);
    void clearChar();
    void clearString();


};

#endif
