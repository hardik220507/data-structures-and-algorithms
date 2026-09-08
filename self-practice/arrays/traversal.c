#include<stdio.h>
int main(){
    int arr[5] = {1,2,3,4,5};
    printf("Elements in the array : [ ");
    for(int i=0;i<5;i++){
        printf("%d ",*(arr+i));
    }
    printf("]\n");
    return 0;
}   
