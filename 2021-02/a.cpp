//hay 2 semaforos, uno del plato y otro de la hamaca

huron{
    // hace algo
    wait(plato);
    // come
    signal(plato);
    // hace algo
    wait(hamaca);
    // duerme
    signal(hamaca);
}