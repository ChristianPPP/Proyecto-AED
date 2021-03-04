int lineal (int a[], int n, int dato)
{
  for (int i=0; i<n; i++)
  {
    if (a[i]==dato)
    {
      return i;
    }
  }
  return -1;
}

void binaria (int a[], int n, int dato)
{
  int b,i,j,k;
  i=0;
  j=n-1;
  b=dato;
  if(dato<=n){
  do
  {
    k=(i+j)/2;
    if (a[k]<=b) 
    {
      i=k+1; 
    }
    if (a[k]>=b)
    {
      j=k-1; 
    }
  }while(i<=j);
  cout<<"Elemento buscado :"<<dato<<endl;
  cout<<"EL ELEMENTO A BUSCAR SI ESTA EN EL ARREGLO: " <<j+1<<endl;
  }
  else{
  cout<<"Elemento no encontrado";
  }
}

void interpolacion (int a[], int n, int dato)
{
  int primero = 0;
  int ultimo = n-1;
  int medio;
  int cont=0;
  int num=dato;
  while(a[primero] != num && cont<=dato)
  {
    medio = primero + ((num - a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
    if(a[medio]<num)
    {
      primero = medio +1;
    }
    else if(a[medio]>num)
    {
      ultimo = medio-1;
    }
    else
    {
      primero = medio;
    }
    cont++;
  }
  if(a[primero]==num)
  {
    for (int i=0; i<n; i++)
    {
      if(a[i]==num)
      {
        cout<<"ELEMENTO ENCONTRADO, EN LA POSICIÓN: "<<i;
        interpolacion<<endl;
        interpolacion<<"ELEMENTO ENCONTRADO, EN LA POSICIÓN: "<<i<<endl;
      }
    }
  }
  else
  {
    cout<<"ELEMENTO NO ENCONTRADO";
    interpolacion<<"ELEMENTO NO ENCONTRADO"<<endl;
  }
}
