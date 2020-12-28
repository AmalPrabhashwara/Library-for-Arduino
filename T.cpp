
#include "Arduino.h"
#include "T.h"
#include<EEPROM.h>
//#include<string.h>

//using namespace std;


const int locationInt=0;
const int locationFloat=100;
const int locationChar=200;
const int locationString=220;
const int stringSize=6;


char T::readChar(int n)
{
char myChar;
myChar=EEPROM.read(locationChar+1+n);
return myChar;
}

/*char* T::readstring(int n)
{
  char myString[stringSize];
  for(int i=0;i<stringSize;i++)
  myString[i]=EEPROM.read((locationString+1)+(n*stringSize)+i);
  char *c=myString;
  return c;
}*/


String T::readstring(int n)
{
  char myString[stringSize];
  for(int i=0;i<stringSize;i++)
  myString[i]=EEPROM.read((locationString+1)+(n*stringSize)+i);
  //char *c=myString;
  return myString;
}


void T::storeString(char x[])
{
  int k=EEPROM.read(locationString);
  for(int i=0;i<stringSize;i++)
  {
    int place=(locationString+1)+(k*stringSize)+(i);
    EEPROM.put(place,x[i]);
  }
  k=k+1;
  EEPROM.write(locationString,k);
}



void T::storeChar(char x)
{
  int k=EEPROM.read(locationChar);
  EEPROM.put(locationChar+1+k,x);
  k=k+1;
  EEPROM.write(locationChar,k);

}

int T::readInt(int n)//this function will return the n th stored integer
{
  int Val;
  EEPROM.get(locationInt+1+n*2,Val);
  return Val;
}

void T::storeInt(int x)
{
  int k=EEPROM.read(locationInt);
  EEPROM.put(locationInt+1+2*k,x);
  k=k+1;
  EEPROM.write(locationInt,k);

}

float T::readFloat(int n)
{
    int Val;
    EEPROM.get(locationFloat+1+n*4,Val);
    return Val;

}

void T::storeFloat(float x)
{
  int k=EEPROM.read(locationFloat);
  EEPROM.put(locationFloat+1+4*k,x);
  k=k+1;
  EEPROM.write(locationFloat,k);
}

void T::clearInt()
{
  for(int i=locationInt;i<locationFloat;i=i+2)
  EEPROM.put(i,0);
}

void T::clearFloat()
{
  for(int i=locationFloat;i<locationChar;i=i+4)
  EEPROM.put(i,0);
}

void T::clearChar()
{
  for(int i=locationChar;i<locationString;i=i+1)
  EEPROM.put(i,0);
}

void T::clearString()
{
for(int i=locationString;i<EEPROM.length();i=i+stringSize)
  EEPROM.put(i,0);
}
