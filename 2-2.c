#include<stdio.h>
#include<stdlib.h>
int selectionsort(int a[],int n);
int main(){
  int n,i,c;
  int *a;
  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));
  if(a==NULL){
    printf("ERROR\n");
    return 1;
  }
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  c=selectionsort(a,n);
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],c);
  free(a);
  return 0;
}

int selectionsort(int a[],int n){
  int i,j,b,min,count=0;
  for(j=0;j<n;j++){     /*for1*/
    min=a[j];
    for(i=j+1;i<n;i++){   /*for2*/
      if(min>a[i]){
        min=a[i];
        b=i;
      }     /*if close*/
      count=count+1;
    }       /*for2 close*/
    if(a[j]>min){
      a[b]=a[j];
      a[j]=min;
      printf("SWAP(%d,%d)\n#",j,b);
      for(i=0;i<n;i++) printf(" %d",a[i]);
      printf("\n");
    }       /*if close*/
  }         /*for1 close*/
  return count;
}
  
  
