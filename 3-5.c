#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count2=0,count5=0;

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
    int result[3],d=0,**c,i,j; 
    c=(int**)malloc((m+1)*sizeof(int*));
    for(i=0;i<=m;i++)c[i]=(int*)malloc((n+1)*sizeof(int));
    if(c==NULL){
        printf("ERROR\n");
        exit(1);
    }
    if(count5==0){
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++)c[i][j]=-1;
        }
    }
    count5+=1;
    if(i==0||j==0){
        c[i][j]=i+j;
    }else{
        if(x[i-1]!=y[j-1])d=1;
        if(c[i-1][j-1]==-1){
            result[0]=ld5(x,i-1,y,j-1)+d;
        }else{
            result[0]=c[i-1][j-1]+d;
        }
        if(c[i-1][j]==-1){
            result[1]=ld5(x,i-1,y,j)+1;
        }else{
            result[1]=c[i-1][j]+1;
        }
        if(c[i][j-1]==-1){
            result[2]=ld5(x,i,y,j-1)+1;
        }else{
            result[2]=c[i][j-1]+1;
        }
        c[i][j]=min(result,3);
    }
    free(c);
    for(i=0;i<=m;i++)free(c[i]);
    return c[m][n];
}

int main(){
    int m,n,cmn;
    char x[100]={},y[100]={};
    scanf("%s %s",x,y);
    m=strlen(x);
    n=strlen(y);
    cmn=ld5(x,m,y,n);
    ld2(x,m,y,n);    
    printf("%d\n",cmn);
    fprintf(stderr,"%d,%d,%d,%d,%d\n",m,n,m*n,count2,count5);
    return 0;
}