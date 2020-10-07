#include <Arduino.h>
const char pass[] = "ABCDEFGH";

void setup() {
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  digitalWrite(8,LOW);
  Serial.println("Inicializado");
}
bool compareChrArray(char* arr1,const char* arr2,int len){
    bool isEqual = true;
    for(int i=0;i<len;i++){
       if(arr1[i]!=arr2[i]){
           isEqual = false; 
       }
    }  
    return isEqual;
}
void loop() {
     if(Serial.available()){
           char leitura[sizeof(pass)];
           Serial.readString().toCharArray(leitura,sizeof(pass));
           Serial.println(leitura);
           Serial.println(pass);
           if(compareChrArray(leitura,pass,sizeof(pass))){
              Serial.println("Porta Aberta");
              digitalWrite(8,HIGH);
              delay(1000);
           }
           digitalWrite(8,LOW);
     }
     delay(1);
}