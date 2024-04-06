#include "Pago.h"

Pago::Pago(Fecha *FP, float MP)
{
    FechaPago=FP;
    MontoPago=MP;
}

Fecha *Pago::getFechaPago()
{
    return FechaPago;
}

float Pago::getMontoPago(){
    return MontoPago;
}
