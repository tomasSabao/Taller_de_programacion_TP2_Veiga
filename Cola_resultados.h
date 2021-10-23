#ifndef COLA_RESULTADOS_H
#define COLA_RESULTADOS_H
#include <string>
#include <iostream>
#include <queue>
#include <mutex>
#include <vector>
#include <map>
#include <utility>

class Cola_resultados
{
    public:
        Cola_resultados();
        virtual ~Cola_resultados();

        void encolar(std::pair<int, std::pair<int,int> > par);
        void agregar_operacion(int id,const std::string &operacion);
        void imprimir_resultados();


    protected:
    private:
        void imprimir_max(int id_op);
        void imprimir_min(int id_op);
        void imprimir_mean(int id_op);
        void imprimir_suma(int id_op);
        std::mutex m;
        std::queue<std::pair<int , std::pair<int,int> >> cola_resultados;
        std::map<int,std::string> mapa_operaciones;
        int operaciones;
        std::vector<std::pair<int , std::pair<unsigned int,int> >> vector_resultados;
};
#endif // COLA_RESULTADOS_H
