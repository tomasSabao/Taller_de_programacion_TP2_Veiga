#include "stdlib.h"
#include "Particion.h"
#include <string.h>
#include "Thread_functions.h"
#include <thread>
#include <pthread.h>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]){
    const char* archivo =argv[1];
    int columnas = atoi(argv[2]);
    int num_workers = atoi(argv[3]);

    Cola_resultados cola_resultados;
    Cola_bloqueante cola;

    std::thread thread_encolador(encolar_operaciones, &cola, &cola_resultados,
     num_workers ,archivo, columnas);
    std::vector<std::thread> thread_vector;
    for (int i=0; i<num_workers; i++){
        std::thread worker_thread(worker_procesar, &cola, &cola_resultados);
        thread_vector.push_back(std::move(worker_thread));
    }

    thread_encolador.join();
    for (int i=0; i<num_workers; i++){
        thread_vector.at(i).join();
    }
    cola_resultados.imprimir_resultados();
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    return 0;
}
