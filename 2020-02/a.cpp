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
    for(int i = 0; i<2; i++){
        lock.acquire();
        while(imprimir == false){
            cv1.wait(&lock);
        }
        cout<<'M';
        imprimir = false;
        cv2.signal();
        lock.release();
    }
}

void xMom::print_A(){
    for(int i = 0; i<2; i++){
        lock.release();
        while(imprimir == true){
            cv2.wait(lock);
        }
        cout << 'A';
        imprimir = false;
        cv1.signal();
        lock.release();
    }
}