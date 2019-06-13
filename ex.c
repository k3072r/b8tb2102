#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void selectionsort(double *array,int *result,int n){
    int i,j,c,space,min;
    for(j=0;j<n-1;j++){
        min=array[j];
        for(i=j+1;i<n;i++){
            if(min>array[i]){min=array[i]; c=i;}
        }
        if(array[j]>min){
            array[c]=array[j];
            array[j]=min;          /*swap array */
            space=result[c];
            result[c]=result[j];
            result[j]=space;       /*swap result */
        }
    }
}

int knn_diag(double *you,int k,double **array,int n,int d,int *result){
    int i,j,answer,count=0;
    double inside;
    double *range;
    range=(double*)malloc(n*sizeof(double));
    if(range==NULL){
        printf("ERROR\n");
        exit(1);
    }
    for(i=0;i<n;i++){
        inside=0;
        for(j=0;j<d;j++){
            inside+=array[i][j]*array[i][j]-you[j]*you[j];
        }
        range[i]=sqrt(inside);
    }
    for(i=0;i<n;i++)printf("%lf ",range[i]);
    printf("\n");
    selectionsort(range,result,n);
    for(i=0;i<k;i++){
        count+=result[i];
        printf("%lf %d\n",range[i],result[i]);
    }
    if(count>=2){
        answer=1;
    }else{
        answer=0;
    }
    return answer;
}


int main(){
    int n,d,i,j,k=3,answer;
    int *result;
    double **array,*you;
    scanf("%d %d",&n,&d);
    result=(int*)malloc(n*sizeof(int));
    array=(double**)malloc(n*d*sizeof(double));
    you=(double*)malloc(d*sizeof(double));
    if(result==NULL||array==NULL||you==NULL){
        printf("ERROR\n");
        return 1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<d;j++){
            scanf("%lf",&array[i][j]);
        }
        scanf("%d",&result[i]);
    }
    for(i=0;i<d;i++)scanf("%lf",&you[i]);
    answer=knn_diag(you,k,array,n,d,result);
    if(answer==0)printf("You are healthy!\n");
    if(answer==1)printf("You have a heart disease!\n");
    free(result);
    free(array);
    free(you);
    return 0;
}