#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int digit=0;
int ope_num[200]={};

void edit_ope(int **c,char *x,int m,char *y,int n);

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
    for(j=0;j<=n;j++)c[0][j]=ld_TP(c,x,0,y,j);
    for(i=1;i<=m;i++){
        for(j=0;j<=n;j++)c[i][j]=ld_TP(c,x,i,y,j);
    }
    edit_ope(c,x,m,y,n);
    free(c);
    for(i=0;i<=m;i++)free(c[i]);
}

void edit_ope(int **c,char *x,int m,char *y,int n){
    int i,flag=0,flag_m=0,flag_n=0;
    if(m!=0&&n!=0){
        int ins_del[2]={c[m][n-1]+1,c[m-1][n]+1};
        if(x[m-1]!=y[n-1]){
            if(c[m-1][n-1]+1<=min(ins_del,2)){
                ope_num[digit]=1;
                flag=1;
            }
        }else{
            if(c[m-1][n-1]<=min(ins_del,2)){
                ope_num[digit]=2;
                flag=1;
            }
        }
        if(flag==0){
            if(ins_del[0]<ins_del[1]){
                ope_num[digit]=3;
                flag_m=1;
            }else{
                ope_num[digit]=4;
                flag_n=1;
            }
        }
        digit+=1;
        edit_ope(c,x,m-1+flag_m,y,n-1+flag_n);
    }else{
        if(m==0){
            for(i=0;i<n;i++){
                ope_num[digit]=3;
                digit+=1;
            }
        }else{
            for(i=0;i<m;i++){
                ope_num[digit]=4;
                digit+=1;
            }
        }
    }
}

void write(char *x,int m,char *y,int n){
    int i,j=0,l;
    int work[200]={};
    char ope[200]="";
    for(l=0;ope_num[l]!=0;l++);         /*l=length of ope_num*/
    for(i=0;i<l;i++){
        work[i]=ope_num[l-1-i];
    }
    for(i=0;i-j<m;i++){
        if(work[i]==3){
            j+=1;
            printf(" ");
        }else{
            printf("%c",x[i-j]);
        }
    }
    printf("\n");
    j=0;
    for(i=0;i-j<n;i++){
        if(work[i]==4){
            j+=1;
            printf(" ");
        }else{
            printf("%c",y[i-j]);
        }
    }
    printf("\n");
    for(i=0;i<l;i++){
        if(work[i]==1)ope[i]='R';
        if(work[i]==2)ope[i]='=';
        if(work[i]==3)ope[i]='I';
        if(work[i]==4)ope[i]='D';
        printf("%c",ope[i]);
    }
    printf("\n");
}

int main(){
    int m,n;
    char x[100],y[100];
    scanf("%s %s",x,y);
    m=strlen(x);
    n=strlen(y);
    TP(x,m,y,n);
    write(x,m,y,n);
    return 0;
}

//R=1,==2,I=3,D=4