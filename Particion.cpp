#include "Particion.h"

Particion::Particion(int comienzo, int fin, const char* archivo, const std::string &op,
    int id_op, int columna, int columnas_dataset){
    this->comienzo = comienzo;
    this->fin = fin;
    this->archivo_a_procesar = archivo;
    this->operacion = op;
    this->id_op = id_op;
    this->columna_a_procesar = columna;
    this->columnas_dataset = columnas_dataset;
    //ctor
}

int Particion::procesar(Cola_resultados* cola){
    std::pair<unsigned int, int> resultado;
    if (this->operacion=="end"){
        return 1;
    }
    if (this->operacion == "max"){
        resultado = this->obtener_maximo();
    }
    if (this->operacion == "min"){
        resultado = this->obtener_minimo();
    }
    if (this->operacion == "sum"){
        resultado = this->obtener_suma();
    }
    if (this->operacion == "mean"){
        resultado = this->obtener_promedio();
    }
    std::pair<int,std::pair<unsigned int, int>> par;
    par.first = this->id_op;
    par.second = resultado;
    cola->encolar(par);
    return 0;
}



std::pair<unsigned int ,int> Particion::obtener_maximo(){
    std::ifstream miArchivo(this->archivo_a_procesar, std::ios::binary);
    unsigned int maximo=0;
    for (int i=this->comienzo; i< this->fin; i++){
        unsigned int numero = this->obtener_numero(miArchivo, i);
        if (numero > maximo){
            maximo = numero;
        }
    }
    std::pair<unsigned int,int> resultado;
    resultado.first = maximo;
    resultado.second = 1;
    miArchivo.close();
    return resultado;
}


std::pair<unsigned int ,int> Particion::obtener_minimo(){
    std::ifstream miArchivo(this->archivo_a_procesar, std::ios::binary);
    unsigned int minimo=0;
    bool primer_elemento = true;
    for (int i=this->comienzo; i< this->fin; i++){
        unsigned int numero = this->obtener_numero(miArchivo, i);
        if (primer_elemento){
            minimo = numero;
            primer_elemento = false;
        } else {
            if (numero < minimo){
                minimo = numero;
            }
        }
    }
    std::pair<unsigned int,int> resultado;
    resultado.first=minimo;
    resultado.second =1;
    miArchivo.close();
    return resultado;
}


std::pair<unsigned int ,int> Particion::obtener_suma(){
    std::ifstream miArchivo(this->archivo_a_procesar, std::ios::binary);
    unsigned int suma=0;
    for (int i=this->comienzo; i< this->fin; i++){
        unsigned int numero = this->obtener_numero(miArchivo, i);
        suma+=numero;
    }
    std::pair<unsigned int,int> resultado;
    resultado.first = suma;
    resultado.second = 1;
    miArchivo.close();
    return resultado;
}

std::pair<unsigned int ,int> Particion::obtener_promedio(){
    std::ifstream miArchivo(this->archivo_a_procesar, std::ios::binary);
    unsigned int suma=0;
    int contador =0;
    for (int i=this->comienzo; i< this->fin; i++){
        unsigned int numero = this->obtener_numero(miArchivo, i);
        suma+=numero;
        contador++;
    }
    std::pair<unsigned int,int> resultado;
    resultado.first = suma;
    resultado.second = contador;
    miArchivo.close();
    return resultado;
}


unsigned int Particion::obtener_numero(std::ifstream &archivoAbierto, int fila){
    char bloqueMemoria[2];
    unsigned int numero = 0;
    int posicion_a_tomar= fila*this->columnas_dataset * 2 + 2* this->columna_a_procesar;
    archivoAbierto.seekg(posicion_a_tomar, std::ios::beg);
    archivoAbierto.read(bloqueMemoria,2);
    memcpy(&numero, bloqueMemoria,2);
    numero = numero >> 8;
    return numero;
}


Particion::~Particion()
{
    //dtor
}
