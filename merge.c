#include "test.h"
void merge(int arr[],int left,int mid,int right){
    int l=mid-left+1;
    int r=right-mid;
    int* L=(int*)malloc(sizeof(int)*l);
    int* R=(int*)malloc(sizeof(int)*r);

    int i;
    for(i=0;i<l;i++)
        L[i]=arr[left+i];
    for(i=0;i<r;i++)
        R[i]=arr[mid+1+i];
    int pos=left;
    int j=0;
    i=0;
    while(i!=l && j!=r){
        if(L[i]<R[j])
            arr[pos++]=L[i++];
        else
            arr[pos++]=R[j++];
    }
    while(i!=l)
        arr[pos++]=L[i++];
    while(j!=r)
        arr[pos++]=R[j++];
}

void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}


void adapter(int arr[],int num){
    merge_sort(arr,0,num-1);
}
int main(){
    test(adapter,"merge sort");
}
