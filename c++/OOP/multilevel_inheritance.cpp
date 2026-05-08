#include<bits/stdc++.h>
using namespace std;


class Person {
public:
  string name;
  int age;
};

class Student : public Person {
public:
  int rollno;
};


//multi level inheritance 
class GradStudent : public Student {
public:
  string researchArea;
};




int main(){
  GradStudent s1;
  s1.name="Tony";
  s1.researchArea="AI";
  cout << "Name: " << s1.name << " " << " and research area is: " << s1.researchArea;
  return 0;
}