#include<bits/stdc++.h>
using namespace std;
class Student {
public:
  string name;
  int rollno;
};
class Teacher {
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