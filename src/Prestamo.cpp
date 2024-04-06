#include "Prestamo.h"
#define TAM 10
using namespace std;
#include <iostream>
Prestamo::Prestamo(int Id)
{
    NumeroPrestamo=Id;
    saldoPendiente=0;
    contadorPago=0;
    MontoAprobado=0;
    NumeroPrestamo=0;
}
int Prestamo::getNumeroPrestamo(){
    return NumeroPrestamo;
}
void Prestamo::setNumeroPrestamo(int numP){
    NumeroPrestamo=numP;
}
Cliente *Prestamo::getCliente(){
    return Clientee;
}

void Prestamo::setCliente(Cliente *cli){
    Clientee = cli;
}
void Prestamo::setFecha(Fecha *feAp){
    FechaAprobacion=feAp;
}
void Prestamo::setMontoAprobado(float MP){
    MontoAprobado=MP;
    saldoPendiente=MP;
}
float Prestamo::getMontoAprobado(){
    return MontoAprobado;
}
bool Prestamo::hacerPagos(Pago *pg){
    bool retorno=false;
    if(contadorPago<TAM){
        lstPago[contadorPago]=pg;
        contadorPago++;
        saldoPendiente -= pg->getMontoPago();
        retorno=true;
    }
    return retorno;
}
Pago **Prestamo::getlstPago(){
    return lstPago;
}
float Prestamo::getSaldoPendiente(){
    return saldoPendiente;
}


int Prestamo::getContadorPagos(){
    return contadorPago;
}
