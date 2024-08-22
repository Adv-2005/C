#include<stdio.h>
#include <stdbool.h>
bool sparse();
int main(){
int n,m,a[100][100],i,j,res;

printf("Enter number of rows and columns");
scanf("%d %d",&n,&m);
printf("Enter array elements");
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        scanf("%d",&a[i][j]);
    }

}
res=sparse(a,n,m);
if(res==true){
    printf("It is a sparse matrix");
}
else{
    printf("It is a dense matrix");


}}
 bool sparse(int arr[100][100],int n,int m){
 int counter=0,i,j;
 for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        if(arr[i][j]==0)
            counter++;

    }
 }
 return counter>((m*n)/2);
 }

