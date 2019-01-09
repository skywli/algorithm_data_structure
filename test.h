#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
void print(int* data,int num){
    int i;
    for(i=0;i<num;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
}
int compare(const void* num1,const void* num2){
    return *(int*)num1-*(int*)num2;
}

int test(void sort (int arr[],int num),const char* name){
    srand(time(0));
    int i;
    int res=0;
    struct timeval start,end;
    gettimeofday(&start,0);
    for(i=0;i<100;i++){
        int num=rand()%100+1;
        int* data=(int*)calloc(1,num*sizeof(int));
        int* base=(int*)calloc(1,num*sizeof(int));
        int j;
        for(j=0;j<num;j++){
            data[j]=rand()%100;
        }
        memcpy(base,data,sizeof(int)*num);
        qsort(base,num,sizeof(int),compare);
        sort(data,num);
        if (memcmp(data,base,0)!=0){
            res=-1;
            break;
        }
    }
    gettimeofday(&end,0);
    if (res==0){
        printf("%s success %ldms\n",name,(end.tv_sec*1000+end.tv_usec/1000)-(start.tv_sec*1000-start.tv_usec/1000));
    }else{
        printf("%s fail\n",name);
    }
}
