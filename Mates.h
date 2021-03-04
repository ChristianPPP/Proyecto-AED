float promedio (float a[], int t)
{
  float sum, prom;
  for (int i=0; i<t; i++)
  {
    sum=sum+a[i];
  }
  prom=sum/t;
  return prom;
}

