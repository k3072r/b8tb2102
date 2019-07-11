#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count2=0,count5=0;
int c[100][100];

int min(int *array,int n){
    int i,min;
    min=array[0];
    for(i=1;i<n;i++){
        if(array[i]<min)min=array[i];
    }
    return min;
}

int ld2(char *x,int m,char *y,int n){
    int result[3],d=0,cmn;
    count2+=1;
    if(m==0||n==0){
        cmn=m+n;
    }else{
        if(x[m-1]!=y[n-1])d=1;
        result[0]=ld2(x,m-1,y,n-1)+d;
        result[1]=ld2(x,m-1,y,n)+1;
        result[2]=ld2(x,m,y,n-1)+1;
        cmn=min(result,3);
    }
    return cmn;
}

int ld5(char *x,int m,char *y,int n){
    int result[3],d=0; 
    count5+=1;
    if(c[m][n]>=0)return c[m][n];
    if(m==0||n==0){
        c[m][n]=m+n;
    }else{
        if(x[m-1]!=y[n-1])d=1;
        result[0]=ld5(x,m-1,y,n-1)+d;
        result[1]=ld5(x,m-1,y,n)+1;
        result[2]=ld5(x,m,y,n-1)+1;
        c[m][n]=min(result,3);
    }
    return c[m][n];
}

int main(){
    int i,j,m,n,cmn;
    char x[100]={},y[100]={};
    while(scanf("%s %s",x,y)!=EOF){
        m=strlen(x);
        n=strlen(y);
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++)c[i][j]=-1;
        }
        cmn=ld5(x,m,y,n);
        ld2(x,m,y,n);    
        printf("%d\n",cmn);
        fprintf(stderr,"%d,%d,%d,%d,%d\n",m,n,m*n,count2,count5);
        count2=0;
        count5=0;
    }
    return 0;
}