#include "test.h"
void insert_sort(int a[],int num){
    int i,j;
    for(i=1;i<num;i++){
        int key=a[i];
        for(j=i-1;key<a[j] && j>=0;j--){
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
}

int main(){
    test(insert_sort,"insert sort");

}
