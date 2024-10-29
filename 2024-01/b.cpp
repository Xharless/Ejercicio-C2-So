#include <iostream>
#include <semaphore.h>
#include "sthread.h"

#define N 42;

static sthread_t thread_S[N];
static sthread_t thread_A[N];
static sthread_t thread_M[N];

static sem_t sem_s, sem_a, sem_m;


int main(){
    int i;
    sem_init(&sem_s,0,1);
    sem_init(&sem_a,0,0);
    sem_init(&sem_m,0,0);
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
    sem_wait(&sem_s);
    cout << 'S';
    sem_post(&sem_a);
    sthread_exit(i)
}
void print_A(i){
    sem_wait(&sem_a);
    cout << 'A';
    sem_post(&sem_m);
    sthread_exit(i)
}
void print_M(i){
    sem_wait(&sem_m);
    cout << 'M';
    sem_post(&sem_s);
    sthread_exit(i)
}