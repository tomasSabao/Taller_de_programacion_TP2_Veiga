#ifndef PARTICIONADOR_H
#define PARTICIONADOR_H

#include "Particion.h"
#include "Cola_bloqueante.h"
#include "Input_manager.h"
#include <vector>
#include <string>
class Particionador
{
    public:
        explicit Particionador(int dataset_cols);
        virtual ~Particionador();

        void particionar(Cola_bloqueante* cola, Input_manager* manager, const char* archivo);
        int get_id_operacion();

    protected:
    private:
        int calcular_particiones(int comienzo, int fin, int filas);
        Particion crear_particion(int comienzo, int fin, int id_op, const char* archivo,
            const std::string &op,int columna,int dataset_cols);
        bool numero_desigual_particiones(int comienzo, int fin, int filas);
        int id_particion;
        int dataset_cols;
};
#endif // PARTICIONADOR_H
