#include "Cola_bloqueante.h"

Cola_bloqueante::Cola_bloqueante()
{
    //ctor
}



void Cola_bloqueante::encolar(Particion particion){
    std::unique_lock<std::mutex> uniqueLock(this->m);
    this->cola.push(particion);
    this->var.notify_all();
}

Particion Cola_bloqueante::desencolar(){
    std::unique_lock<std::mutex> uniqueLock(this->m);
    while (this->cola.empty()){
        this->var.wait(uniqueLock);
    }
    this->queue_mutex.lock();
    Particion particion = this->cola.front();
    this->cola.pop();
    this->queue_mutex.unlock();
    return particion;
}


Cola_bloqueante::~Cola_bloqueante()
{
    //dtor
}
