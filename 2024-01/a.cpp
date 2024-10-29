#include <iostream>
#include <semaphore.h>
#include "sthread.h"

#define N 42;

static sthread_t thread_S[N];
static sthread_t thread_A[N];
static sthread_t thread_M[N];

int main(){
    int i;
    for(i = 0; i<N; i++){
        sthread_create(&(thread_S[i]), &print_S, i);
        sthread_create(&(thread_A[i]), &print_A, i);
        sthread_create(&(thread_M[i]), &print_M, i);
    }
    for(i = 0; i<N; i++){
        sthread_join(thread_S[i]);
        sthread_join(thread_A[i]);
        sthread_join(thread_M[i]);
    }
}

void print_S(i){
    cout << 'S';
    sthread_exit(i)
}
void print_A(i){
    cout << 'A';
    sthread_exit(i)
}
void print_M(i){
    cout << 'M';
    sthread_exit(i)
}

/* el problema de utilizar hebras es que si bien podemos imprimir las letras,
no nos asegura que la palabra que se vaya a formar sea SAM  */