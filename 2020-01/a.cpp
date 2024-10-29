#include <lock>
// ejercicio de lock
class XThreads {
    private:
        int saldo;
        Lock lock;
    public:
        void XThreads();
        int giro(plata);
        int abono(plata);
}

void XThreads(){
    saldo = 20000;
}

int XThreads::abono(plata){
    if(saldo + plata > 200000){
        return -1;
    } else {
        lock.acquire();
        saldo = saldo + plata;
        lock.release();
    }

    return saldo;
}

int XThreads::giro(plata){
    if(saldo - plata < 10000){
        return -1;
    } else {
        lock.acquire();
        saldo = saldo - plata;
        lock.release();
    }
    return saldo;
}