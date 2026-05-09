#include<bits/stdc++.h>
using namespace std;


class Student {
public:
  string name;
  
  //constructor overloading
  Student(){
    cout << "This is non parameterized constructor"<<endl;
  }
  
  
  //constructor overloading
  Student(string name){
    this->name=name;
    cout<< "This is parameterized constructor"<<endl;
  }
  
};


class Print {
public:

//function overloading
  void show(int x){
    cout << "Integer: " << x << endl;
  }
  void show(char x){
    cout << "Character: " << x << endl;
  }
};


int main(){
  Student s1;
  Student s2("Tony Stark");
  
  
  Print p1;
  p1.show(5);
  p1.show('%');
  return 0;
}