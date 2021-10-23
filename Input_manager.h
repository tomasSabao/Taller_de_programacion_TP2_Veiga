#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <iostream>
#include <string>
#include <sstream>

class Input_manager
{
    public:
        Input_manager();
        virtual ~Input_manager();
        int leer_linea();
        int obtener_comienzo();
        int obtener_fin();
        int obtener_filas();
        int obtener_columna();
        std::string obtener_operacion();
    protected:
    private:
    std::string obtener_elemento(int num_elemento);
    std::string buffer;
};
#endif // INPUT_MANAGER_H
