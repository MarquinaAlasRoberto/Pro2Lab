#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        Fecha(int d, int m, int a);
        void mostrarFecha();


    protected:

    private:
        int Dia;
        int Mes;
        int Anio;
};

#endif // FECHA_H
