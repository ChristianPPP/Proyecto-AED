
//Ordenamiento por seleccion
void seleccion (float a[], int n); 
void seleccion (float a[], int n) 
{
  int min,i,j,aux;
  for (i=0; i<n-1; i++) 
  {
    min=i;
    for(j=i+1; j<n; j++)
    {
      if(a[min] > a[j])
      {
        min=j;
      }                  
    }
    if(i!=min)
    {
      aux=a[min]; 
      a[min]=a[i];
      a[i]=aux;
    }           
  }
} 

//Ordenamiento por burbuja
void burbuja (float a[], int n);
void burbuja (float a[], int n)
{
  int aux;
  for (int i=0; i<n; i++)
  {
    for (int j=i+1; j<n; j++)
    {
      if (a[j]<a[i])
      {
        aux=a[i];
        a[i]=a[j];
        a[j]=aux;
      }
    }
  }
}

//Ordenamiento por insersion
void insersion (float a[], int n);
void insersion (float a[], int n)
{
  int pos,aux;
  for (int i=0; i<n; i++)
  {
    pos=i;
    aux=a[i];
    while((pos>0)&&(a[pos-1]>aux))
    {
      a[pos]=a[pos-1];
      pos--;
    }
    a[pos]=aux;
  }
}


//Ordenamiento Merge Sort (Llamar primero a funcion dividir)
void fusionar(float a[],int pinicial,int pfinal,int medio);
void fusionar(float a[],int pinicial,int pfinal,int medio)
{
  int i,j,k, temp[pfinal-pinicial+1];
  i=pinicial;
  k=0;
  j=medio+1;
  while(i<=medio && j<=pfinal)
  {
    if(a[i]<a[j])
    {
      temp[k]=a[i];
      k++;
      i++;
    }
    else
    {
      temp[k]=a[j];
      k++;
      j++;
    }
  }
  while (i<=medio)
  {
    temp[k] = a[i];
    k++;
    i++;
  }
  while(j<=pfinal)
  {
    temp[k]=a[j];
    k++;
    j++;
  }
  for(i=pinicial; i<=pfinal; i++)
  {
    a[i]= temp[i-pinicial];
  }
}

void dividir(float a[], int inicial, int final);
void dividir(float a[], int inicial, int final)
{
  int mitad;
  if(inicial < final)
  {
    mitad=(inicial+final)/2;
    dividir(a,inicial,mitad);
    dividir(a,mitad+1,final);
    fusionar(a,inicial,final,mitad);
  }
}



//Ordenamiento quicksort(Llamar primero a funcion ordenar)
int mitad (float a[], int pinicial, int pfinal);
int mitad (float a[], int pinicial, int pfinal)
{
  return a[(pinicial+pfinal)/2];
}

void ordenar (float a[], int pinicial, int pfinal);
void ordenar (float a[], int pinicial, int pfinal)
{

  int i = pinicial;
  int j = pfinal;
  int piv= mitad(a,pinicial,pfinal);
  int temp;
  do
  {
    while(a[i]<piv)
    {
      i++;
    }
    while(a[j]>piv)
    {
      j--;
    }
    if(i<=j)
    {
      temp = a[i];
      a[i]= a[j];
      a[j]=temp;
      i++;
      j--;
    }
  }
  while(i<=j);
  if (pinicial<j)
  {
    ordenar(a,pinicial,j);
  }
  if (i<pfinal)
  {
    ordenar(a,i,pfinal);
  }
}



void ordenar_Calif (float a[], int n)
{
  int opc;
  do 
  {
    ofstream orden;
    orden.open("Colegio/ordenamiento", ios::app);
    cout<<"\nMenu\n";
    cout<<"1.- Ordenamiento por selección\n";
    cout<<"2.- Ordenamiento por burbuja\n";
    cout<<"3.- Ordenamiento por insercion\n";
    cout<<"4.- Ordenamiento por MergeSort\n";
    cout<<"5.- Ordenamiento por QuickSort\n";
    cout<<"6.- Salir\n";
    cout<<"Elija el ordenamiento que desea aplicar: ";
    cin>>opc;
    switch (opc)
    {
      case 1:
      orden<<"Lista de notas ordenadas con el algoritmo por seleccion\n";
      seleccion (a, n); 
      imprimira (a, n);
      cout<<endl;
      break;
      case 2:
      orden<<"Lista de notas ordenadas con el algoritmo por burbuja\n";
      burbuja (a, n);
      imprimira (a, n);
      cout<<endl;
      break;
      case 3:
      orden<<"Lista de notas ordenadas con el algoritmo por insersion\n";
      insersion (a, n);
      imprimira (a, n);
      cout<<endl;
      break;
      case 4:
      orden<<"Lista de notas ordenadas con el algoritmo por mergesort\n";
      dividir(a, 0, n-1);
      imprimira (a, n);
      cout<<endl;
      break;
      case 5:
      orden<<"Lista de notas ordenadas con el algoritmo por quicksort\n";
      ordenar(a, 0, n-1);
      imprimira(a, n);
      cout<<endl;
      break;
      case 6:
      cout<<"Saliendo...\n";
      break;
      default:
      cout<<"Opcion no valida.\n";
    }
    orden.close();
  } while(opc!=6);
}