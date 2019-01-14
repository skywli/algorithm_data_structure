#include "test.h"
#include <stdio.h>
int max_heapify(int arr[],int index,int size){
    int l=2*index+1,r=2*index+2;
    int largest;
    if(l<size && arr[l]>arr[index])
        largest=l;
    else
        largest=index;
    if(r<size && arr[r]>arr[largest])
        largest=r;
    //exchange index and largest item
    if(largest!=index){
        int temp=arr[index];
        arr[index]=arr[largest];
        arr[largest]=temp;
        max_heapify(arr,largest,size);
    }
}
//build heap from bottom to top
int max_heap_build(int arr[],int size){
    int i;
    for(i=(size-1)/2;i>=0;i--)
        max_heapify(arr,i,size);
}
void  heap_sort(int arr[],int size){
    max_heap_build(arr,size);
    int i;
    //exchange from index[size-1,1] with 0 item
    for(i=size-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        max_heapify(arr,0,i);
    }


}
int main(){
    test(heap_sort,"heap sort");
}
