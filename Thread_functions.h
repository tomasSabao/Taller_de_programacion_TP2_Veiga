#ifndef THREAD_FUNCTIONS_H
#define THREAD_FUNCTIONS_H

#include "Cola_bloqueante.h"
#include "Cola_resultados.h"
#include "Input_manager.h"
#include "Particionador.h"

void encolar_operaciones(Cola_bloqueante* cola, Cola_resultados* result,
    int num_workers, const char* archivo, int dataset_cols);

void worker_procesar(Cola_bloqueante* cola, Cola_resultados* results);

#endif // THREAD_FUNCTIONS_H
