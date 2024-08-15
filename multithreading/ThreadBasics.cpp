#pragma once
#include<iostream>
#include<queue>
#include<thread>
#include<chrono>

using namespace std;

void fun(){
    for(int i=0;i<1000;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    // STD::THREAD
        // thread class can be used to create threads.
        // thread class offers default constructer to create a thread object, it also parametrized constructor to pass a callable, lamda as a parameter as well as the parameters of the callable/lamda 
    thread t1;
    cout<<t1.get_id()<<endl;

    thread t2([](){
        cout<<this_thread::get_id()<<endl;
        cout<<"Second thread"<<endl;
    });

    // THREAD::JOIN()
        //used for joining the thread with the main thread so that the main thread would wait for the completion of the child thread.
        // if thread is not joinable, then thread.join() shall cause an std::system_error. Hence it's safer to use thread::joinable() before joining it.
    if(t1.joinable()) {
        cout<<"yes it's joinable"<<endl;
        t1.join();
    }

    this_thread::sleep_for(chrono::milliseconds(5));

    // THREAD::DETACH
        // detaching the thread allows the thread to run independently of the thread that creates and manages it. Once a thread is joined it cannot be detaced
    if(t1.joinable()){
        cout<<"yes it's detachable"<<endl;
        t1.detach();
    }

    cout<<thread::hardware_concurrency()<<endl;

}