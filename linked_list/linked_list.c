#include<stdio.h>
#include<stdlib.h>

//defining a structure for creating linked list
struct hotel {
    char* item;
    int price;
    struct hotel *ptr; //pointer
}; //node

//initializing the linked list with user given values 
struct hotel* linked_list() {
    //initializing address pointer with null
    struct hotel* head;
    struct hotel* item1 = NULL;
    struct hotel* item2 = NULL;
    struct hotel* item3 = NULL;
    struct hotel* item4 = NULL;
    //allocating heap memory for nodes
    item1 = malloc(sizeof(struct hotel));
    item2 = malloc(sizeof(struct hotel));
    item3 = malloc(sizeof(struct hotel));
    item4 = malloc(sizeof(struct hotel));
    //assigning values to data part
    item1->item = "Dosa";
    item2->item = "idle";
    item3->item = "bori";
    item4->item = "bongal";
    /*
    here I don't know how to integrate loops with linked list for user input
    so I have used repeated code
    */
    //getting user input and store it on nodes 
    printf("\nEnter Item price - 1: ");
    scanf("%i",&item1->price);

    printf("\nEnter Item price - 2: ");
    scanf("%i",&item2->price);
    
    printf("\nEnter Item price - 3: ");
    scanf("%i",&item3->price);
    
    printf("\nEnter Item price - 4: ");
    scanf("%i",&item4->price);
    printf("\n");
    
    //linking part
    item1->ptr = item2;
    item2->ptr = item3;
    item3->ptr = item4;
    item4->ptr = NULL;
    head = item1;

    return head;
}

void display_list(struct hotel *i) {
    //using while loop to display the items in linked list
    while (i != NULL) 
    {
        printf("%s\t%d\n",i->item,i->price);
        i = i->ptr; //here the actual linking comes into action
    }
    
}

//used to determine the size of each node
void size(struct hotel *i) {
    while (i != NULL)
    {
        printf("%ld\n",sizeof(i));
        i = i->ptr;
    }
    
}

int main() {
    printf("Linked List implementation");
    //passing linked list function as a argument 
    display_list(linked_list());
    //size(linked_list());
}

