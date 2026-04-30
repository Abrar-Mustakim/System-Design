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
  


  //Constructor
  
  
  
  //non-parameterized constructor
  // Teacher(){
  //   cout<<"Hi!! I am Constructor"<<endl;
  //   dept="Computer Science and Engineering";
  // }
  
  
  //copy constructor
  Teacher(Teacher &orgObj){
    cout<< "This is a Copy Constructor" << endl;
    this->name= orgObj.name;
    this->dept=orgObj.dept;
    this->subject=orgObj.subject;
    this->salary=45000;
  }
  
  
  //parameterized constructor 
  Teacher(string name, string dept, string subject, double salary){
    this->name=name; // left = object  member, right = parameter
    this->dept=dept; //(*this).dept
    this->subject=subject;
    this->salary=salary;
    
  }
  
  
  //constructor overload===polymorphism
   

 
  
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
  
  void getInfo(){
    //we can also skip this here as c++ automatically assumes those are members unless there is ambiguity
    cout << this->name << " " << this->dept << " " << this->subject << " " << this->getSalary() << endl;
  }
  
};


int main() 
{
    cout << "Hello, World!" <<endl;
    // Teacher t1; //Constructor Call
    // t1.name="Mustakim";
    // //t1.dept="CSE";
    // t1.subject="Compiler Design";
    // t1.setSalary(85000);
    // cout << t1.name << " " << t1.dept << " " << t1.subject << " " << t1.getSalary() <<endl;
    // t1.changeDept("CS");
    
    
    // cout << t1.name << " " << t1.dept << " " << t1.subject << " " << t1.getSalary() << endl;
    
    
    Teacher t2("Taki", "CS", "Machine Learning", 90000);
    cout << t2.name << " " << t2.dept << " " << t2.subject << " " << t2.getSalary() << endl;
    
    Teacher t3(t2); //default copy constructor --invoke
    t3.getInfo();
    
    
    Teacher t4(t2); //custom copy constructor
    t4.getInfo();
    
    
    return 0;
}