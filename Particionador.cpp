#include "Particionador.h"

Particionador::Particionador(int dataset_cols)
{
    this->id_particion = 0;
    this->dataset_cols = dataset_cols;
    //ctor
}

int Particionador::calcular_particiones(int comienzo, int fin, int filas){
    int particiones = (fin - comienzo)/ filas;
    if ((fin - comienzo) % filas != 0){
        particiones +=1;
    }
    return particiones;
}

Particion Particionador::crear_particion(int comienzo, int fin, int id_op, const char* archivo,
    const std::string &op,int columna,int dataset_cols){
    Particion unaParticion(comienzo,fin,archivo,op,this->id_particion,columna, dataset_cols);
    return unaParticion;
}

int Particionador::get_id_operacion(){
    return this->id_particion;
}

void Particionador::particionar(Cola_bloqueante* cola, Input_manager* manager,
    const char* archivo){
    int comienzo = manager->obtener_comienzo();
    int fin = manager->obtener_fin();
    int fila = manager->obtener_filas();
    std::string op = manager->obtener_operacion();
    int columna = manager->obtener_columna();
    int particiones = this->calcular_particiones(comienzo,fin,fila);
    bool desigual = this->numero_desigual_particiones(comienzo, fin, fila);
    for (int i=0; i<particiones-1; i++){
        int pos_comienzo = comienzo+i*fila;
        int pos_fin = comienzo + (i+1) * fila;
        Particion unaParticion = this->crear_particion(pos_comienzo,pos_fin,this->id_particion
        ,archivo,op, columna, this->dataset_cols);
        cola->encolar(unaParticion);
    }
    if (desigual){
        int filas_a_agregar = (fin - comienzo) % fila;
        int pos_comienzo = comienzo+fila*(particiones-1);
        int pos_final=comienzo + fila * (particiones-1)+ filas_a_agregar;
        Particion particion = this->crear_particion(pos_comienzo, pos_final, this->id_particion,
        archivo,op, columna, this->dataset_cols);
        cola->encolar(particion);
    } else {
        int pos_comienzo = comienzo + fila*(particiones-1);
        int pos_final = comienzo + fila * particiones;
        Particion particion = this->crear_particion(pos_comienzo, pos_final, this->id_particion,
        archivo, op, columna, this->dataset_cols);
        cola->encolar(particion);
    }
    this->id_particion++;
}



bool Particionador::numero_desigual_particiones(int comienzo, int fin, int filas){
    if ((fin - comienzo) % filas == 0){
        return false;
    }
    return true;
}

Particionador::~Particionador()
{
    //dtor
}
