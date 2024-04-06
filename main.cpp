#include <iostream>
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#include "Prestamo.h"
#define TAM 10
using namespace std;

int menu(){
    int op;
    cout << "MENU DE OPCIONES\n";
    cout << "1. Agregar Cliente a la lista\n";
    cout << "2. Agregar Agregar prestamo a la lista\n";
    cout << "3. Hacer pago de prestamo\n";
    cout << "4. Mostrar lista de cliente\n";
    cout << "5. Mostrar lista de prestamos\n";
    cout << "6. Mostrar detalle del prestamo\n";
    cout << "7. Salir\n";
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}
Cliente *agregarCliente(){
Cliente *Clientee;
int Id;
string N,A;
    cout<<"Escriba en este orden: el ID, Nombre, Apellido del cliente para poder agregarlo"<<endl;
    cin>>Id;
    cin>>N;
    cin>>A;
    Clientee= new Cliente(Id,N,A);
    return Clientee;
}
Cliente *buscarCliente(Cliente *lstC[],int contC, int id){
    bool encontrado=false;
    int contador=0;
    Cliente *cli=NULL;
    while(contador < contC && !encontrado){
        if(lstC[contador]->getIdCliente()==id){
            encontrado=true;
            cli=lstC[contador];
        }
        else{
            contador++;
        }
    }
    return cli;
}
Prestamo *agregarPrestamo(Cliente *lstcliente[],int cont){
    int idclie,nump,d,m,a;
    Prestamo *Pres=NULL;
    float MontoAprobadoo;
    cout<<"Digite el ID del cliente\n";
    cin>>idclie;
    Cliente *cli=buscarCliente(lstcliente,cont,idclie);
    if(cli){
        cout<<"Ingrese el numero del prestamo"<<endl;
        cin>>nump;
        cout<<"Ingrese el monto aprobado\n";
        cin>>MontoAprobadoo;
        cout<<"Digite la fecha del prestamo en formato dia, mes y anio\n";
        cin>>d;
        cin>>m;
        cin>>a;
        Fecha *feAP=new Fecha(d,m,a);
        Pres= new Prestamo(nump);
        Pres->setCliente(cli);
        Pres->setMontoAprobado(MontoAprobadoo);
        Pres->setFecha(feAP);
    }
    return Pres;
}
Prestamo *buscarPrestamo(Prestamo *lstP[],int contP, int nup){
    bool encontrado=false;
    int contador=0;
    Prestamo *pe=NULL;
    while(contador < contP && !encontrado){
        if(lstP[contador]->getNumeroPrestamo()==nup){
            encontrado=true;
            pe=lstP[contador];
        }
        else{
            contador++;
        }
    }
    return pe;
}
void mostrarCliente(Cliente *lst[],int cont){
   if(cont == 0){
    cout<<"La lista se encuentra llena.\n";
   }
   else{
    cout<<"ID\T.nombre\tApellido\n";
    for(int i=0;i <cont;i++){
        Cliente *cli=lst[i];
        cout<<cli->getIdCliente()<<"\t";
        cout<<cli->getNombre()<<"\t";
        cout<<cli->getApellido()<<"\t";
    }
   }
}
void mostrarPrestamo(Prestamo *lst[],int cont){
   if(cont == 0){
    cout<<"La lista esta llena\n";
   }
   else{
    cout<<"ID\T.cliente\tMonto\n";
    for(int i=0;i <cont;i++){
        Prestamo *Pre=lst[i];
        cout<<Pre->getNumeroPrestamo()<<"\t";
        cout<<Pre->getCliente()->getNombre() <<"  "<< Pre->getCliente()->getApellido()<<"\t";
        cout<<Pre->getMontoAprobado()<<"\t";
    }
   }
}

int main()
{
    int opc;
    Cliente *lstCli[TAM];
    Prestamo *lstPrestamo[TAM];
    Cliente *cli=NULL;
    Prestamo *Pres=NULL;
    int contCli=0,contPr=0,IdClie,IdPres,nump,dp,mp,ap;
    float montop;
    do{
        system("cls");
         opc=menu();
 switch(opc){
    case 1:
      //Agregar clientes
       if (contCli < TAM){
                    lstCli[contCli] = agregarCliente();
                    contCli++;
                    cout << "El cliente se agrego con exito\n";
                }
                else{
                    cout << "La lista de cliente esta llena\n";
                }
      break;
     case 2:
      //Agg prestamo.
      {
      Prestamo *prest=agregarPrestamo(lstCli,contCli);
      if(prest){
        if (contPr < TAM){
                    lstPrestamo[contPr] = Pres;
                    contCli++;
                    cout << "El cliente se agrego con exito\n";
                }
                else{
                    cout << "La lista de prestamos se encuentra llena o vacia\n";
                }
      }
      else{
        cout<<"No fue posible encontrar al cliente, imposible agregar prestamo.";
        }
      }
      break;
     case 3:
      //Pago de prestamo
       {
           cout<<"digite el numero de prestamo\n";
           cin>>nump;
      Prestamo *prest=buscarPrestamo(lstPrestamo,contPr,nump);
      if(prest){
        if (contPr < TAM){
            ///se encontro
            cout<<"Digite el monto";
            cin>>montop;
            cout<<"Digite el dia de pago";
            cin>>dp;
            cout<<"Digite el mes de pago";
            cin>>mp;
            cout<<"Digite el anyo de pago";
            cin>>ap;
            Fecha *fp= new Fecha(dp,mp,ap);
            Pago *pg=new Pago(fp,montop);
            prest->hacerPagos(pg);
            cout<<"Pago realizado correctamente\n";
            }else{
                cout << "La lista de prestamos esta llena o vacia\n";
                }
      }
      else{
        cout<<"no se encontro el cliente, prestamo denegado";
        }
      }
      break;
     case 4:
      //Mostrar cliente
      mostrarCliente(lstCli,contCli);
      break;
     case 5:
      //Mostrar prestamo
      mostrarPrestamo(lstPrestamo,contPr);
      break;
     case 6:{
      //Detalles

      cout<<"Digite el numero de prestamo\n";
      cin>>nump;
      Prestamo *prest=buscarPrestamo(lstPrestamo,contPr,nump);
      if(prest){
        if (contPr < TAM){
                //Si se encuentra:
                cout<<"Mostrando los detalles del prestamo\n";
                cout<<"El numero del prestamo es: "<< prest->getCliente()->getNombre() <<" "<< prest->getCliente()->getApellido() <<endl;
                cout<<"Monto aprobado del prestamo "<< prest->getMontoAprobado()<<endl;
                cout<<"Fecha del prestamo ";
                prest->getFechaAprobacion();
                if(prest->getContadorPagos()==0){
                    cout<<"No hay ningun pago \n";
                }
                else{
                    cout<<"LISTA DE PAGO REALIZADOS\n";
                    cout<<"Fecha\tMonto\n";
                    Pago **lstP=prest->getlstPago();
                    for(int i=0; i<prest->getContadorPagos();i++){
                    Pago *pg=lstP[i];
                    pg->getFechaPago()->mostrarFecha();
                    cout<<"\t";
                    cout<<pg->getMontoPago()<<endl;
                    }
                }
        }
            else{
                cout << "La lista de prestamos esta llena o vacia\n";
            }
      }
      else{
        cout<<"No se ha encontrado al cliente en el sistema.";
        }
      }
      break;
    case 7:
    cout << "Saliendo del Programa...\n";
    break;
    default:
    cout << "Error, esta opcion no esta definida";
    break;

 }
system("pause");
    }while(opc!=7);
}

