#include<stdio.h>

void toh(int n, char source, char aux, char dest)
{
  if(n==1)
  {
    printf("MOVE DISC FROM %d TO %d\n", source, dest );
  }
  else
  {
    toh(n-1,source,dest,aux);
    printf("MOVE DISC FROM %d TO %d\n", source, dest);
    toh(n-1,aux,source,dest);
  }
}

int main()
{
  int num;
  printf("ENTER NUMBER OF DISCS:");
  scamf("%d",&num);
  toh(num,'A','B','C');
  return 0;
}
