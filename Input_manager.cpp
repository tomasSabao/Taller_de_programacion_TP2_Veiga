#include "Input_manager.h"

Input_manager::Input_manager()
{
    //ctor
}


int Input_manager::leer_linea(){
    getline(std::cin, this->buffer);
    if (this->buffer.length() == 0){
    return 1;
    }
    return 0;
}


int Input_manager::obtener_comienzo(){
    std::string palabra = this->obtener_elemento(1);
    return std::stoi(palabra);
}

int Input_manager::obtener_fin(){
    std::string palabra = this->obtener_elemento(2);
    return std::stoi(palabra);
}

int Input_manager::obtener_filas(){
    std::string palabra = this->obtener_elemento(3);
    return std::stoi(palabra);
}

int Input_manager::obtener_columna(){
    std::string palabra = this->obtener_elemento(4);
    return std::stoi(palabra);
}

std::string Input_manager::obtener_operacion(){
    std::string palabra = this->obtener_elemento(5);
    return palabra;
}

std::string Input_manager::obtener_elemento(int num_elemento){
    std::stringstream ss(this->buffer);
    std::string palabra;
    for (int i=0; i<num_elemento; i++){
        ss >> palabra;
    }
    return palabra;
}

Input_manager::~Input_manager()
{
    //dtor
}
