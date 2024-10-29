#include <lock>

class xMom{
    private:
        Lock lock
        CV cv1, cv2;
        bool imprimir;
    public: 
        void Xmom();
        void print_M();
        void print_A();
}

void Xmom(){
    imprir = true;
}

void xMom::print_M(){
    lock.acquire();
    while(imprimir == false){
        cv1.wait(&lock);
    }
    cout<<'M';
    imprimir = false;
    cv2.signal();
    lock.release();
}

void xMom::print_A(){
    lock.release();
    while(imprimir == true){
        cv2.wait(lock);
    }
    cout << 'A';
    imprimir = false;
    cv1.signal();
    lock.release();
}