#ifndef COLA_BLOQUEANTE_H
#define COLA_BLOQUEANTE_H

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Particion.h"

class Cola_bloqueante
{
    public:
        Cola_bloqueante();
        virtual ~Cola_bloqueante();

        void encolar(Particion particion);
        Particion desencolar();
    protected:
    private:
    std::mutex m;
    std::mutex queue_mutex;
    std::condition_variable var;
    std::queue<Particion> cola;
};

#endif // COLA_BLOQUEANTE_H
