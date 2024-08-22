#include <stdio.h>
int fact(int n);
int fact (int n){
int i,res=1;
for (i=1; i<=n;i++)
res=res*i;
return res;
}

int main(){
int n,r,result;
printf("enter n and r");
scanf("%d %d",&n,&r);
if(r==0){
    printf("%d",n);
}
else if(r==n){
    printf("1");
}
else{
    result=fact(n)/(fact(n-r)*fact(r));
printf("%d",result);
}

}
