#include "Cola_resultados.h"

Cola_resultados::Cola_resultados()
{
    this->operaciones=0;
    //ctor
}


void Cola_resultados::encolar(std::pair<int, std::pair<int,int> > par){
    m.lock();
    //this->cola_resultados.push(par);
    this->vector_resultados.push_back(par);
    m.unlock();
}

void Cola_resultados::agregar_operacion(int id, const std::string &operacion){
    this->mapa_operaciones[id] = operacion;
    this->operaciones+=1;
}

void Cola_resultados::imprimir_max(int id_op){
    unsigned int aux=0;
    for (unsigned int i=0; i<this->vector_resultados.size(); i++){
            if (this->vector_resultados.at(i).first == id_op){
                if (vector_resultados.at(i).second.first > aux){
                    aux=vector_resultados.at(i).second.first;
                }
            }
    }
    std::cout<<aux<<std::endl;
}

void Cola_resultados::imprimir_min(int id_op){
    unsigned int aux =0;
    bool primer_valor = true;
    for (unsigned int i=0; i<this->vector_resultados.size(); i++){
        if (this->vector_resultados.at(i).first == id_op){
            if (primer_valor){
                aux = this->vector_resultados.at(i).second.first;
                primer_valor = false;
            } else {
                if (this->vector_resultados.at(i).second.first < aux){
                    aux = this->vector_resultados.at(i).second.first;
                }
            }
        }
    }
    std::cout<<aux<<std::endl;
}


void Cola_resultados::imprimir_mean(int id_op){
    unsigned int suma =0;
    unsigned int contador =0;
    for (unsigned int i=0; i<this->vector_resultados.size(); i++){
        if (this->vector_resultados.at(i).first == id_op){
            suma += this->vector_resultados.at(i).second.first;
            contador += this->vector_resultados.at(i).second.second;
        }
    }
    std::cout<<suma<<"/"<<contador<<std::endl;
}

void Cola_resultados::imprimir_suma(int id_op){
    unsigned int suma =0;
    for (unsigned int i=0; i<this->vector_resultados.size(); i++){
        if (this->vector_resultados.at(i).first == id_op){
            suma += this->vector_resultados.at(i).second.first;
        }
    }
    std::cout<<suma<<std::endl;
}

void Cola_resultados::imprimir_resultados(){
    for (int i=0; i<this->operaciones; i++){
        std::string operacion = this->mapa_operaciones[i];
        if (operacion == "sum"){
            this->imprimir_suma(i);
        }
        if (operacion == "max"){
            this->imprimir_max(i);
        }
        if (operacion == "mean"){
            this->imprimir_mean(i);
        }
        if (operacion == "min"){
            this->imprimir_min(i);
        }
    }
}


Cola_resultados::~Cola_resultados()
{
    //dtor
}
