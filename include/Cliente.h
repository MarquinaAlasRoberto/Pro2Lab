#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
using namespace std;

class Cliente
{
    public:
        Cliente(int Id, string N, string A);
        int getIdCliente();
        string getNombre();
        string getApellido();

    protected:

    private:
        int IdCliente;
        string Nombre;
        string Apellido;
};

#endif // CLIENTE_H
