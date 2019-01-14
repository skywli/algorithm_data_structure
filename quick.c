#include "test.h"

void quick_sort(int a[],int left,int right){
    int key=a[left];
    int i=left+1,j=right;
    if(i<j){
        while(i<j){
            while(key<=a[j] && i<j)
                j--;
            while(key>=a[i] && i<j)
                i++;
            if(i<j){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        a[left]=a[i];
        a[i]=key;
        quick_sort(a,left,i-1);
        quick_sort(a,i+1,right);
    }
}
void adapter(int arr[],int num){
    quick_sort(arr,0,num-1);
}
int main(){
    test(adapter,"quick sort");
}
