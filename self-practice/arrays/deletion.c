#include<stdio.h>
void delete(int *arr,int pos,int n){
    for(int i=pos+1;i<n;i++){ 
        arr[i-1] = arr[i];
    }
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int pos;
    printf("Enter the position from which you want to delete the element: ");
    scanf("%d",&pos);
    delete(arr,pos,n);
    printf("After deletion : [ ");
    for(int i=0;i<n-1;i++){
        printf("%d ",*(arr+i));
    }
    printf("]\n");
    return 0;
}