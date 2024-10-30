#include <lock>

class huron{
    private:
        int plato, hamaca;
        Lock lock1, lock2;
        CV cv1, cv2;
    public: 
        huron();
        void comer();
        void dormir();
}

huron::huron(){
    plato = 4;
    hamaca = 1;
}

void huron::comer(){
    lock1.acquire();
    while(plato == 0){
        cv1.wait(&lock1);
    }
    plato--; 
    // come 
    plato++;
    cv1.signal();
    lock1.release();
}

void huron::dormir(){
    lock2.acquire();
    while(hamaca==0){
        cv2.wait(&lock2);
    }
    hamaca--;
    //durmiendo
    hamaca++;
    cv2.signal();
    lock.release();
}