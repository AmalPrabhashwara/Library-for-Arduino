#include <T.h>



T kamal;

void setup() {
  // put your setup code here, to run once
  Serial.begin(115200);
  //kamal.clearString();
  //kamal.clearFloat();
  //kamal.storeString("pop");
  //kamal.storeString("kkop");
  //kamal.storeString("rerr");
  //kamal.storeString("iois");
  // kamal.storeFloat(45.1);
  //Serial.println(kamal.readFloat(0));
  
   Serial.println(kamal.readstring(0));
   Serial.println(kamal.readstring(1));
   Serial.println(kamal.readstring(2));
   Serial.println(kamal.readstring(3));
   //Serial.println(kamal.readFloat(0));
}

void loop() {
  // put your main code here, to run repeatedly:

}
