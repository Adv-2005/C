#include<stdio.h>
int main(){
int arr[100],i,j,k,n;
printf("Enter number of elements");
scanf("%d",&n);
 printf("Enter elements :\n");
for(i=0;i<n;i++){
   scanf("%d",&arr[i]);
}
for (i=0;i<n-2;i++){
      for (j=i+1;j<n-1;j++){
	  for (k=j+1;k<n;k++){
	      if (arr[i]+arr[j]+arr[k]==0){
		  printf ("%d, %d, %d\n", arr[i], arr[j], arr[k]);
		}
	    }}

		}

	    }

