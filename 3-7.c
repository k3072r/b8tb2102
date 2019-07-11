#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void selectionsort(int a[],char **V,int n){
  int i,j,b,min;
  char work[25];
  for(j=0;j<n;j++){ 
    min=a[j];
    for(i=j+1;i<n;i++){
      if(min>a[i]){
        min=a[i];
        strcpy(work,V[i]);
        b=i;
      }
    }
    if(a[j]>min){
      a[b]=a[j];
      a[j]=min;
      strcpy(V[b],V[j]);
      strcpy(V[j],work);
    }
  }
}

int min(int *array,int n){
    int i,min;
    min=array[0];
    for(i=1;i<n;i++){
        if(array[i]<min)min=array[i];
    }
    return min;
}

int ld_TP(int **c,char *x,int i,char *y,int j){
    int result[3],d=0;
    if(i==0||j==0){
        c[i][j]=i+j;
    }else{
        if(x[i-1]!=y[j-1])d=1;
        result[0]=c[i-1][j-1]+d;
        result[1]=c[i-1][j]+1;
        result[2]=c[i][j-1]+1;
        c[i][j]=min(result,3);
    }
    return c[i][j];
}

int TP(char *x,int m,char *y,int n){
    int i,j,**c;
    c=(int**)malloc((m+1)*sizeof(int*));
    for(i=0;i<=m;i++)c[i]=(int*)malloc((n+1)*sizeof(int));
    if(c==NULL){
        printf("ERROR\n");
        exit(1);
    }
    for(j=0;j<=n;j++)c[0][j]=ld_TP(c,x,0,y,j);
    for(i=1;i<=m;i++){
        for(j=0;j<=n;j++)c[i][j]=ld_TP(c,x,i,y,j);
    }
    free(c);
    for(i=0;i<=m;i++)free(c[i]);
    return c[m][n];
}

int main(){
    int n,i;
    int *length;
    char x[25];
    char **V;
    scanf("%d",&n);
    length=(int*)malloc(n*sizeof(int));
    V=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)V[i]=(char*)malloc(25*sizeof(char));
    if(V==NULL||length==NULL){
        printf("ERROR\n");
        return 1;
    }
    for(i=0;i<n;i++)scanf("%s",V[i]);
    while(scanf("%s",x)!=EOF){
        for(i=0;i<n;i++)length[i]=TP(x,strlen(x),V[i],strlen(V[i]));
        selectionsort(length,V,n);
        for(i=0;i<3;i++)printf("rank: %d, ed = %d, string = %s\n",i+1,length[i],V[i]);
    }
    free(V);
    for(i=0;i<n;i++)free(V[i]);
    return 0;
}