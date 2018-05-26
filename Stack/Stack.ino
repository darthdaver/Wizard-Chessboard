#include <StackList.h>

// create a stack of String.
StackList <String> stack;

void setup() {
  //start serial communication
  Serial.begin (9600);
  
  // set the printer of the stack.
  stack.setPrinter (Serial);
  
}

void loop() {

  String demo1 = "Cavallo in A5";
  String demo2 = "Cavallo da A5 in B8";
  
  String temp = String(strtok(demo1.c_str(), " "));
  
  stack.push(temp);

  while(temp != NULL){
    temp = String(strtok(NULL," "));
    
    if(temp != NULL){
      stack.push(temp);
    }
  }

  Serial.print("Number of items in the stack:  ");
  Serial.println(stack.count());
  Serial.println("List of the items:");
  
  while(!stack.isEmpty()){
    Serial.println(stack.pop());
  }

  temp = String(strtok(demo2.c_str(), " "));
  
  stack.push(temp);

  while(temp != NULL){
    temp = String(strtok(NULL," "));
    
    if(temp != NULL){
      stack.push(temp);
    }
  }

  
  Serial.print("Number of items in the stack:  ");
  Serial.println(stack.count());
  Serial.println("List of the items:");
  
  while(!stack.isEmpty()){
    Serial.println(stack.pop()); 
  }

  Serial.println();
  delay(3000);
}
