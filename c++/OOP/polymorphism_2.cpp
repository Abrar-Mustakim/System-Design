#include<bits/stdc++.h>
using namespace std;

class Parent {
public:
  void getInfo(){
    cout << "This is parent class " << endl;
  }
  
  virtual void hello(){
    cout << "Hello from Parents\n";
  }
};

class Children : public Parent {
public:
  void getInfo(){
    cout << "This is child class" << endl;
  }
  
  void hello(){
    cout << "Hello from Child\n";
  }
};


int main(){
  Children c1;
  c1.getInfo();
  
  
  Parent p1;
  p1.getInfo();
  
  
  c1.hello();
  p1.hello();
  
  return 0;
}