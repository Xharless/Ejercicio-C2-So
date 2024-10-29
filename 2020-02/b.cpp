#include <lock>
#include <semaphore.h>


Semaphore sM = 1;
Semaphore sA = 0;

void print_M(){
    for(int i = 0; i<2; i++){
        wait(sM);
        cout<<'M';
        signal(sA);
    }
}

void print_A(){
    for(int i = 0; i<2; i++){
        wait(sA);
        cout << 'A';
        signal(sM);
    }
}