
/*
se requieren 3 semaforos
mutex = 1
beber = 20
rellenar = 0
*/

Bebedor(){
    while(TRUE){
        wait(beber);
        wait(mutex);
        // toma
        signal(mutex);
        signal(rellenar);
    }
}
Rellenador(){
    while(TRUE){
        wait(rellenar);
        wait(mutex);
        //rellena
        wait(mutex);
        wait(beber);
    }
}