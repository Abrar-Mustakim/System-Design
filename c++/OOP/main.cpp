#include <bits/stdc++.h>
using namespace std;


class Teacher { 
  
private:
  double salary;
  
public://access modifiers

  //access modifiers
  //private: data & methods accessible inside class-->default
  //public: data and methods accessible to everyone
  //protected: data and methods accessible inside class & to its derived class

 
  //properties //attributes
  string name;
  string dept;
  string subject;
  //double salary;
  
  //methods //member functions
  void changeDept(string newDept){
    dept = newDept;  
  }
  
  void setSalary(double s){
    salary=s;
  }
  
  double getSalary(){
    return salary;
  }
  
};


int main() 
{
    cout << "Hello, World!" <<endl;
    Teacher t1;
    t1.name="Mustakim";
    t1.dept="CSE";
    t1.subject="Compiler Design";
    t1.setSalary(85000);
    t1.changeDept("CS");
    
    
    cout << t1.name << " " << t1.dept << " " << t1.subject << " " << t1.getSalary();
    return 0;
}