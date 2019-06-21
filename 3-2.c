#include<stdio.h>
#include<string.h>

int min(int *array,int n){
    int i,min;
    min=array[0];
    for(i=1;i<n;i++){
        if(array[i]<min)min=array[i];
    }
    return min;
}

int ld(char *x,int m,char *y,int n){
    int result[3],d=0,cmn;
    if(m==0||n==0){
        cmn=m+n;
    }else{
        if(x[m-1]!=y[n-1])d=1;
        result[0]=ld(x,m-1,y,n-1)+d;
        result[1]=ld(x,m-1,y,n)+1;
        result[2]=ld(x,m,y,n-1)+1;
        cmn=min(result,3);
    }
    return cmn;
}

int main(){
    int m,n,cmn;
    char x[100]={},y[100]={};
    scanf("%s %s",x,y);
    m=strlen(x);
    n=strlen(y);
    cmn=ld(x,m,y,n);
    printf("%d\n",cmn);
    return 0;
}