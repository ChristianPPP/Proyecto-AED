using namespace std;
void ingreso_Notas(int n, int t, float a[][50], string nombres[], string apellidos[], string correos[]);
void ingreso_Notas(int n, int t, float a[][50], string nombres[], string apellidos[], string correos[])
{
  for (int i=0; i<n; i++)
  {
    cout<<"\nIngrese el nombre del estudiante N°"<<i+1<<": ";
    cin>>nombres[i];
    cout<<"\nIngrese el apellido del estudiante N°"<<i+1<<": ";
    cin>>apellidos[i];
    cout<<"\nIngrese el correo electronico del estudiante N°"<<i+1<<": ";
    cin>>correos[i];
  }
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<t; j++)
    {
      cout<<"\nIngrese la calificación N°"<<j+1<<" del estudiante "<<apellidos[i]<<": ";
      cin>>a[i][j];
    }
  }
}


void archivorcalif (int n, int t, float a[][50], string nombres[], string apellidos[], string correos[], string inst, int ai, int af, string m, float prom, string nd, string ad, int ci);
          //1 num estudiantes 2 num notas 3 arr notas 4 arr nombres es 5 apellodos 6 correos estudi 7 in esduca supe 8 año inicio 9 año fin 10 materia 11 promedio
void archivorcalif (int n, int t, float a[][50], string nombres[], string apellidos[], string correos[], string inst, int ai, int af, string m, float prom, string nd, string ad, int ci)
{
  ofstream rcalif;
  float total, tn[50], promc;
  int contadora=0;
  int contadors=0;
  int contadorr=0; 
  rcalif.open("Colegio/calificaciones", ios::app);
      rcalif<<"\nINSTITUCION DE EDUCACION SUPERIOR "<<inst;
      rcalif<<"\nREPORTE DE CALIFICACIONES";
      rcalif<<"\nAno lectivo: "<<ai<<"-"<<af;
      rcalif<<"\nMateria: "<<m;
      rcalif<<"\nLista de estudiantes: ";
      for (int i=0; i<n; i++)
      {
        rcalif<<"\nEstudiante N° "<<i+1;
        rcalif<<"\nNombre: "<<nombres[i];
        rcalif<<"\nApellido: "<<apellidos[i];
        rcalif<<"\nCorreo: "<<correos[i];
        for (int j=0; j<t; j++)
        {
          rcalif<<"\nNota N° "<<j+1<<": "<<a[i][j];
          total=total+a[i][j];
        }
        prom=total/t;
        tn[i]=prom;
        rcalif<<"\nTotal: "<<prom; 
        if (prom>=14)
        {
          contadora=contadora+1;
        }
        else if (prom<14 && prom>=9)
        {
          contadors=contadors+1;
        }
        else
        {
          contadorr=contadorr+1;
        }
        total=0;
      }
      float sum;
      for (int i=0; i<n; i++)
      {
        sum=sum+tn[i];
      }
      promc=sum/t;
      rcalif<<"\nRESUMEN";
      rcalif<<"\nPromedio del curso: "<<promc;
      rcalif<<"\nTotal";
      rcalif<<"\nAprobados (14-20) "<<contadora;
      rcalif<<"\nSuspenso (09-13) "<<contadors;
      rcalif<<"\nReprobados (01-08) "<<contadorr;
      rcalif<<"\nDocente";
      rcalif<<"\n"<<nd<<" "<<ad;
      rcalif<<"\n"<<ci;  
  rcalif.close();
}



void imprimira (float a[], int n);
void imprimira (float a[], int n)
{
  ofstream orden;
  orden.open("Colegio/ordenamiento", ios::app);
  cout<<"\nCalificaciones Ordenadas\n";
  for(int i=0; i<n; i++)
  {
    cout<<"|"<<a[i]<<"|";
    orden<<"|"<<a[i]<<"|";
  }
  orden<<endl;
  orden.close();
}