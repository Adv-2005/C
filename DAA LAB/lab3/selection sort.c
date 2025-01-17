#include<stdio.h>
#include<stdlib.h>
int i,j,k;
void selectionSort(int *a, unsigned int n)
{
unsigned int i,j,min;
int temp;
int opcount=0;
for(i= 0;i<n-1;i++)
{
min=i;
for(j=i + 1;j<n;j++)
{
++opcount;
if(a[j ]<a[min])
min=j;
}

temp = a[i];
a[i] = a[min];
a[min]=temp;
}
printf("\nOperation Count %d\n",opcount);
}

int main() {
int *a;
int i,n = 5;

for ( j=0; j < 4; j++)
{
a = (int *)malloc(sizeof(int)*n);
for ( k=0; k< n; k++)
a[k] = n-k;
printf("Elements are ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
selectionSort(a,n);
printf("Elements after selection sort ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
free(a);
n = n + 5;
}
return 0;
}
