#ifndef PAGO_H
#define PAGO_H
#include "Fecha.h"
#include <iostream>
using namespace std;

class Pago
{
    public:
        Pago(Fecha *FP, float MP);
        Fecha *getFechaPago();
        float getMontoPago();

    protected:

    private:
        float MontoPago;
        Fecha *FechaPago;
};

#endif // PAGO_H
