#include <lock>



// aqui es con bloqueos y wait

class XThreads {
    private:
        int saldo;
        Lock lock;
        CV cv1, cv2; // para lo del bloqueo
    public:
        void XThreads();
        int giro(plata);
        int abono(plata);
}

void XThreads(){
    saldo = 20000;
}

int XThreads::abono(plata){
    lock.acquire();
    while(saldo + plata > 200000){
        cv1.wait(&lock);
    }
    saldo = saldo + plata;
    cv2.signal();
    lock.release();
    return saldo;
}

int XThreads::giro(plata){
    lock.acquire();
    while(saldo - plata < 10000){
        cv2.wait(&lock);
    }
    saldo = saldo - plata;
    cv1.signal();
    lock.release();
    return saldo;
}