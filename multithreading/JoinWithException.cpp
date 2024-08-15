#include<iostream>
#include<thread>
#include "common.h"

using namespace std;

void foo(){
    cout<<"foo"<<endl;
}
void other_operations(){
    cout<<"In other operations"<<endl;
    throw runtime_error("this is runtime error\n");
}
int main(){
    thread t(foo);
    thread_guard tg(t);
    try{
        other_operations();
    }catch(...){
    }

    //better way to deal with this is RAII
        //Resource acquisition is initialisation
        //constructor acquire resources, destructor release resources
}