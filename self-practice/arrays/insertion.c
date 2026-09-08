#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int key,pos;
    printf("Enter the element you want to insert:");
    scanf("%d",&key);
    printf("Enter its position: ");
    scanf("%d",&pos);
    int arr1[2*n];
    for(int i=0;i<pos;i++){
        arr1[i] = arr[i];
    }
    arr1[pos] = key;
    for(int i=pos;i<n;i++){
        arr1[i+1] = arr[i];
    }
    printf("After insertion : [ ");
    for(int i=0;i<n+1;i++){
        printf("%d ",*(arr1+i));
    }
    printf("]\n");
    return 0;

}