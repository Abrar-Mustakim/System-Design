#include<bits/stdc++.h>
using namespace std;

class Person {
public:
  string name;
  int age;
  
  
  Person(string name, int age){
    this->name=name;
    this->age=age;
  }
  Person(){
    cout << "This is from Parent Constructor" << endl;
  } //default constructor
};


class Student : public Person {
public:
  int rollno;
  
  Student(string name, int age, int rollno) : Person(name, age){
    
    cout << "This is from Child Constructor" << endl;
    this->rollno=rollno;
    
  }
  
  void getInfo(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    //cout << "Roll No: " << rollno << endl;
  }
  
};


int main(){
  Student s1("avay", 32, 50);
  // s1.name="aray";
  // s1.age=23;
  // s1.rollno=31;
  s1.getInfo();
  
  cout << "Hello World " << endl;
  return 0;
}