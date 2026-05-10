#include<bits/stdc++.h>
using namespace std;


void fun(){
    //int x=0;
    static int x = 0; //now what will happen is, x will be run/daclared ones, and will store in seperate static or a heap area
    // and when we will again call the fun(), the x=0 will not happen, as it is static, rather, it will deprived from another
    cout << "X is: " << x << endl;
    x++;
}

class ABC {
public:
    ABC(){
        cout << "constructor\n";
    }
    ~ABC(){
        cout << "destractor\n";
    }
};


int main(){
    fun();
    fun();
    fun();

    if(true){
        //ABC obj;
        static ABC obj; //now it will run for lifetime
    }
    cout << "end of main functions" << endl;


    return 0;
}