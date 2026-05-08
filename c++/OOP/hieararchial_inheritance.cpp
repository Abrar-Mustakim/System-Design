#include<bits/stdc++.h>
using namespace std;
class Person {
public:
  string name;
};

//hierarchial inheritance
class Student : virtual public Person {
public:
  //string name;
  int rollno;
};
class Teacher : virtual public Person { //virtual means share only one common base class object
public:
  string subject;
  double salary;
};
//multiple inheritance
class TA : public Student, public Teacher {
public:
  string researchArea;
};
int main(){
  TA t1;
  t1.name="Tony";
  t1.subject="CSE";
  t1.researchArea="AI";
  cout << t1.name << " " << t1.subject << " " << t1.researchArea;
  return 0;
}