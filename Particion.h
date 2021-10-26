#ifndef PARTICION_H
#define PARTICION_H

#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>
#include "Cola_resultados.h"
#include <string>
#include <utility>
class Particion
{
    public:
        Particion(int comienzo, int fin, const char* archivo,const std::string &op,
            int id_op, int columna, int columnas_dataset);
        virtual ~Particion();
        void agregar_elementos();
        const int procesar(Cola_resultados* cola);
    protected:
    private:
        const std::pair<unsigned int ,int> obtener_maximo();
        const std::pair<unsigned int ,int> obtener_minimo();
        const std::pair<unsigned int ,int> obtener_suma();
        const std::pair<unsigned int ,int> obtener_promedio();
        unsigned int obtener_numero(std::ifstream &archivoAbierto, int fila);

        std::string operacion;
        int comienzo;
        int fin;
        const char* archivo_a_procesar;
        int id_op;
        int columna_a_procesar;
        int columnas_dataset;
};

#endif // PARTICION_H

