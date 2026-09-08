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
void deleteFromBeginning(struct Node** node){
    if (*node==NULL){
        printf("List is empty\n");
    }
 
    *node = (*node)->next;
}

void deleteFromEnd(struct Node** node){
    if (*node==NULL){
        printf("List is empty\n");
    }
    if ((*node)->next==NULL){
        *node = NULL;
    }
    struct Node* temp = *node;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

void deleteFromPosition(struct Node** node,int pos){
    struct Node* temp = *node;
    if (*node==NULL){
        printf("List is empty\n");
    }
    if (pos==1){
        *node = NULL;
    }
    int i=1;
    while(temp->next!=NULL && i<(pos-1)){
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;  
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
    printf("Deletion from beginning : ");
    deleteFromBeginning(&node);
    display(node);
    printf("Deletion from end : ");
    deleteFromEnd(&node);
    display(node);
    int pos;
    printf("Enter the position from which you want to delete : ");
    scanf("%d",&pos);
    deleteFromPosition(&node,pos);
    display(node);
    return 0;
}


