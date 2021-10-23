#include "Thread_functions.h"


void encolar_operaciones(Cola_bloqueante* cola, Cola_resultados* result,
    int num_workers, const char* archivo, int dataset_cols){
    Input_manager input_manager;
    Particionador particionador(dataset_cols);
    int leyo = 0;
    while (leyo != 1){
        leyo = input_manager.leer_linea();
        if (leyo != 1){
            particionador.particionar(cola, &input_manager, archivo);
            result->agregar_operacion(particionador.get_id_operacion()-1 ,
            input_manager.obtener_operacion());
        }
    }
    for (int i =0; i< num_workers; i++){
        Particion particion(0,0,archivo,"end",0,0,dataset_cols);
        cola->encolar(particion);
    }
}

void worker_procesar(Cola_bloqueante* cola, Cola_resultados* results){
    while (true){
        Particion particion = cola->desencolar();
        int continuar = particion.procesar(results);
        if (continuar == 1){
            break;
        }
    }
}
