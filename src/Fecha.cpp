#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int d, int m, int a)
{
    Dia=d;
    Mes=m;
    Anio=a;

}

void Fecha::mostrarFecha()
{
    cout << Dia << "//" << "//" << Anio << endl;
}
