#include<stdio.h>
#include<stdlib.h>
// int create(int *arr,int n){
//     for(int i=0;i<n;i++){
//         scanf("%d",arr+i);
//     }
//     return *arr;
// }
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(*arr) * n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    // *arr = create(arr,n);
    printf("Array : [ ");
    for(int i=0;i<n;i++){
        printf("%d ",*arr+i);
    }
    printf("]\n");
    free(arr);
    return 0;
}
