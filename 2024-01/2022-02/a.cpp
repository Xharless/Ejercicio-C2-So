class Bebedor{
    private:
        Lock lock;
        Cv cv1, cv2;
        int bebe, rellena;
    public:
        void beber();
        void rellenar();
        Bebedor():
}

Bebedor::Bebedor(){
    bebe = 0;
    rellena = 0;
}

void Bebedor::beber(){
    lock.acquire();
    while((bebe-rellena) = MAX){
        cv1.wait(&lock);
    }
    bebe++;
    cv2.signal();
    lock.release();
}

void Bebedor::rellenar(){
    lock.acquire();
    while(bebe == rellena){
        cv2.wait(&lock);
    }
    rellena++;
    cv1.signal();
    lock.release();
}