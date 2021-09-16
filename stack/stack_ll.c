#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct stack {
    int data;
    struct stack* next;
}*top=NULL;

void push();
void pop();
void display();
void isEmpty();
void isFull();

void main()
{
push();

}

void push(){
    struct stack* tmp = malloc(sizeof(struct stack));
    int element;
    int ch;
    while(1){
        printf("Add: 1\tExit: 2\n");
        scanf("%d",&ch);
        if(ch == 1){
        printf("\nEnter the Element to Add: ");
        scanf("%d",&element);
        }
        else{
            display();
        }
        if (tmp == NULL) {
        printf("Memory was not created\n");
    } 
    else {
        tmp->data = element;
        tmp->next = top;
        top = tmp;
        printf("Pushed Element %d\n",top->data);
    }
 }
    
}

void display(){
    while( top!=NULL){
        printf("%d ",top->data);
        top = top->next;
    }
}

void pop(struct stack* top){
    if(top == NULL) {
        printf("Stack is Empty");
    }
    else {

    
    struct stack* temp;
    int data;
    temp = top;
    data = top->data;
    top = top->next;
    printf("Deleted element %d",data);
    free(temp);
}

}