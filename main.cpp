#include <iostream>
#include "Mates.h"
#include <fstream>
#include "ntlib.h"
#include "odmlib.h"

using namespace std;




void ordenar_Calif (float a[], int n);

int main ()
{
  string nombred, apellidod, institucion;
  string materia;
  ofstream rcalif;
  rcalif.open("Colegio/calificaciones", ios::app);
  int cedulad, ainicio, afin;
  int nestudiantes, nnotas, contadora=0, contadors=0, contadorr=0;
  float notas[50][50], total, tnotas[50], prom, tprom;
  string estudiantesn[50], estudiantesa[50], estudiantesc[50];
  int opc, res1=0;
  cout<<"\t\t****SISTEMA DE REGISTRO DE CALIFICACIONES****\n\n";
  cout<<"Ingrese su nombre: ";
  cin>>nombred;
  cout<<"\nIngrese su apellido: ";
  cin>>apellidod;
  cout<<"\nIngrese su número de cédula: ";
  cin>>cedulad;
  cout<<"\nIngrese el nombre de la institución: ";
  cin>>institucion;
  cout<<"\nIngrese el año de inicio: ";
  cin>>ainicio;
  cout<<"\nIngrese el año de fin: ";
  cin>>afin;
  rcalif<<"Nombre del docente: "<<nombred;
  rcalif<<"\nApellido del docente: "<<apellidod;
  rcalif<<"\nCI del docente: "<<cedulad;
  rcalif<<"\nInstitucion a la que pertenece el docente: "<<institucion<<endl;
  rcalif.close();
  do 
  {
    cout<<"\nMenu\n";
    cout<<"1.- Registro de calificaciones\n";
    cout<<"2.- Resumen de calificaciones\n";
    cout<<"3.- Ordenamiento de calificaciones\n";
    cout<<"4.- Busqueda de calificaciones\n";
    cout<<"5.- Salir\n";
    cin>>opc;
    contadora=0;
    contadors=0;
    contadorr=0; 
    switch (opc)
    {
      case 1:
      cout<<"Ingrese el nombre de la materia: ";
      cin>>materia;
      cout<<"\nIngrese el numero de estudiantes: ";
      cin>>nestudiantes;
      cout<<"\nIngrese el numero de notas: ";
      cin>>nnotas;
      ingreso_Notas(nestudiantes, nnotas, notas, estudiantesn, estudiantesa, estudiantesc);
      break;
      case 2:
      cout<<"\nINSTITUCION DE EDUCACION SUPERIOR "<<institucion;
      cout<<"\nREPORTE DE CALIFICACIONES";
      cout<<"\nAno lectivo: "<<ainicio<<"-"<<afin;
      cout<<"\nMateria: "<<materia;
      cout<<"\nLista de estudiantes: ";
      for (int i=0; i<nestudiantes; i++)
      {
        cout<<"\nEstudiante N° "<<i+1;
        cout<<"\nNombre: "<<estudiantesn[i];
        cout<<"\nApellido: "<<estudiantesa[i];
        cout<<"\nCorreo: "<<estudiantesc[i];
        for (int j=0; j<nnotas; j++)
        {
          cout<<"\nNota N° "<<j+1<<": "<<notas[i][j];
          total=total+notas[i][j];
        }
        tprom=total/nnotas;
        tnotas[i]=tprom;
        cout<<"\nTotal: "<<tprom;
        if (tprom>=14)
        {
          contadora=contadora+1;
        }
        else if (tprom<14 && tprom>=9)
        {
          contadors=contadors+1;
        }
        else
        {
          contadorr=contadorr+1;
        }
        total=0;
      }
      prom=promedio(tnotas,nestudiantes);
      cout<<"\nRESUMEN";
      cout<<"\nPromedio del curso: "<<prom;
      cout<<"\nTotal";
      cout<<"\nAprobados (14-20) "<<contadora;
      cout<<"\nSuspenso (09-13) "<<contadors;
      cout<<"\nReprobados (01-08) "<<contadorr;
      cout<<"\nDocente";
      cout<<"\n"<<nombred<<" "<<apellidod;
      cout<<"\n"<<cedulad;
      if (res1==0)
      {
        archivorcalif (nestudiantes, nnotas,  notas, estudiantesn, estudiantesa,  estudiantesc,  institucion,  ainicio, afin,  materia,  prom,  nombred,  apellidod, cedulad);
        res1=res1+1;
      } 
      break;
      case 3:
      ordenar_Calif (tnotas, nestudiantes);
      break;
      case 4:
      break;
      case 5:
      cout<<"Saliendo...\n";
      break;
      default:
      cout<<"Opcion no valida.\n";
    }
  } while(opc!=5);
  return 0;
}