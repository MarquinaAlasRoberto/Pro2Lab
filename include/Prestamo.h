#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include "Pago.h"
#include "Fecha.h"
#define TAM 10

class Prestamo
{
    public:
        Prestamo(int id);
        int getNumeroPrestamo();
        void setNumeroPrestamo(int NumPre);
        Cliente *getCliente();
        void setCliente(Cliente *cli);
        void setFecha(Fecha *feAp);
        Fecha *getFechaAprobacion();
        void setMontoAprobado(float MP);
        float getMontoAprobado();
        bool hacerPagos(Pago *pg);
        Pago **getlstPago();
        float getSaldoPendiente();
        int getContadorPagos();

    protected:

    private:
        int NumeroPrestamo;
        Cliente *Clientee;
        Fecha *FechaAprobacion;
        float MontoAprobado;
        Pago *lstPago[TAM];
        float saldoPendiente;
        int contadorPago;
};

#endif // PRESTAMO_H
