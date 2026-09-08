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
    if(node==NULL){
        return newNode;
    }
    struct Node* temp = node;
    while(temp->next!=NULL) temp = temp->next;
    temp->next = newNode;
    return node;   
}

void insertAtBeginning(struct Node** node,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *node;
    *node = newNode;
}

void insertAtEnd(struct Node** node,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = *node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct Node** node,int data,int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(pos==1){
        newNode->next=*node;
        *node = newNode;
    }
    struct Node* temp = *node;
    int i=1;
    while(i<(pos-1)){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(struct Node* node){
    struct Node* temp = node;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
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
    int key;
    printf("\nEnter the element you want to insert at the beginning: ");
    scanf("%d",&key);
    insertAtBeginning(&node,key);
    display(node);
    printf("\nEnter the element you want to insert at the end: ");
    scanf("%d",&key);
    insertAtEnd(&node,key);
    display(node);
    printf("\nEnter the element you want to insert : ");
    scanf("%d",&key);
    int pos;
    printf("Enter its position:");
    scanf("%d",&pos);
    insertAtPosition(&node,key,pos);
    display(node);
    return 0;
}