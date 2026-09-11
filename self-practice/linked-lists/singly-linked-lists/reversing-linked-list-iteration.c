#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* create(struct Node* node,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(node==NULL){
        return newNode;
    }
    struct Node* temp = node;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return node;
}
void reverse(struct Node** node){
    struct Node *current,*prev,*next;
    current = *node;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *node = prev;
}
void display(struct Node* node){
    struct Node* temp = node;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* node = NULL;
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        int value;
        scanf("%d",&value);
        node = create(node,value);
    }
    display(node);
    reverse(&node);
    printf("Reversing the linked list: ");
    display(node);
    return 0;
}