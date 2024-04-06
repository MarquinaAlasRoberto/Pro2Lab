#include "Cliente.h"

Cliente::Cliente(int Id, string N, string A)
{
    IdCliente=Id;
    Nombre=N;
    Apellido=A;
}

int Cliente::getIdCliente(){
    return IdCliente;
    }

string Cliente::getNombre(){
    return Nombre;
    }

string Cliente::getApellido(){
    return Apellido;
}
