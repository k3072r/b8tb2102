#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void TP(char *x,int m,char *y,int n){
    int i,j,**c;
    c=(int**)malloc((m+1)*sizeof(int*));
    for(i=0;i<=m;i++)c[i]=(int*)malloc((n+1)*sizeof(int));
    if(c==NULL){
        printf("ERROR\n");
        exit(1);
    }
    printf("   ");
    for(j=0;j<n;j++)printf(" %c",y[j]);
    printf("\n");                       /*line 1 */
    printf(" ");
    for(j=0;j<=n;j++){
        c[0][j]=ld_TP(c,x,0,y,j);
        printf(" %d",c[0][j]);
        }
    printf("\n");                       /*line 2 */
    for(i=1;i<=m;i++){
        printf("%c",x[i-1]);
        for(j=0;j<=n;j++){
            c[i][j]=ld_TP(c,x,i,y,j);
            printf(" %d",c[i][j]);
        }
        printf("\n");
    }
    free(c);
    for(i=0;i<=m;i++)free(c[i]);
}

int main(){
    int m,n;
    char x[100],y[100];
    scanf("%s %s",x,y);
    m=strlen(x);
    n=strlen(y);
    TP(x,m,y,n);
    return 0;
}