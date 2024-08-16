#include<iostream>
#include<thread>
#include "thread_guard.h"


void foo(){
    std::cout<<"foo"<<std::endl;
}
void other_operations(){
    std::cout<<"In other operations"<<std::endl;
    throw std::runtime_error("this is runtime error\n");
}
void JoinWithException(){
    std::thread t(foo);
    mt::thread_guard tg(t);
    try{
        other_operations();
    }catch(...){
    }

    //better way to deal with this is RAII
        //Resource acquisition is initialisation
        //constructor acquire resources, destructor release resources
}