#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* create(struct Node* node,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (node == NULL){
        return newNode;
    }
    struct Node* temp = node;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newNode;
    return node;
}
void display(struct Node* node){
    if(node==NULL){
        printf("List is empty");
    }
    else{
        struct Node* temp = node;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter elements:\n ");
    struct Node* list = NULL;
    for(int i=0;i<n;i++){
        int value;
        scanf("%d",&value);
        list = create(list,value);
    }
    display(list);
    return 0;
}