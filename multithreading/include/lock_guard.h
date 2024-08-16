#include<mutex>

namespace mt{
    class lock_guard{
        std::mutex& m;
        public:
        lock_guard(std::mutex& _m):m(_m){
            
        }
        ~lock_guard(){
            m.try_lock();
            m.unlock();
        }
        void lock(){
            m.lock();
        }
        void unlock(){
            m.unlock();
        }

    };
}

