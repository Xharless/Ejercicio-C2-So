class MakeCOLock{
    private:
        Lock lock;
        Cv cv1, cv2;
        int Ocount;
        int Ccount;
        int COcount;
    public:
        void CArrives();
        void OArrives();
        void MakeCO():
        MakeCOLock();
}

MakeCOLock::MakeCOLock(){
    Ocount = 0;
    Ccount = 0;
    COcount = 0;
}
void MakeCOLock::CArrives(){
    lock.acquire();
    Ccount++;
    cv1.signal();
    while(Ocount == 0){
        cv2.wait(&lock);
    }
    MakeCO();
    lock.release();
}

void MakeCOLock::OArrives(){
    lock.aquire();
    Ocount++;
    cv2.signal();
    while(CArrives == 0){
        cv1.wait(&lock);
    }
    MakeCO();
    lock.release();
}

void MakeCOLock::MakeCO(){
    lock.acquire();
    COcount++;
    lock.release();
}