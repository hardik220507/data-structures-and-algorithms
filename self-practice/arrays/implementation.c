#include<stdio.h>
// int create(int *arr,int n){
//     for(int i=0;i<n;i++){
//         scanf("%d",arr+i);
//     }
//     return *arr;
// }
int main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // *arr = create(arr,n);
    printf("Array : [ ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
    return 0;
}