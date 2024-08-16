#include <stdio.h>
void swap(int *p1,int *p2){
int temp;
temp=*p1;
*p1=*p2;
*p2=temp;

}

int main(){
int a=20;
int b=10;
printf("%d %d", a,b);
printf("After Swapping\n");
swap(&a,&b);
printf("%d %d",a,b);

return 0;
}
