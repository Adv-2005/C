#include <stdio.h>
int main(){
int *p,a,**d;
a=20;
p=&a;
d=&p;

printf("%d\n",p);
p=p+1;
printf("%d",*d);
return 0;
}
