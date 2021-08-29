#include<stdio.h>
#include<stdlib.h>

struct node
{
    char* data;
    struct node *next;
};

void print_list(struct node* n) {
    while (n != NULL) {
        printf("%s",n->data);
        n = n->next;
    }
}
//adding in front
void add_front(struct node** head_ref) {
    struct node* new_node = malloc(sizeof( struct node));
    new_node->data = "kitten\n";
    new_node->next = *head_ref;
    *head_ref = new_node;
}

//adding in middle
void add_middle(struct node* pre_node) {
    if (pre_node == NULL) {
        printf("%s","nothing");
    } else {
        struct node* middle_node = malloc(sizeof(struct node));
        middle_node->data = "parrot\n";
        middle_node->next = pre_node->next;
        pre_node->next = middle_node;
    }
}

//adding at last
void add_end(struct node** head_ref) {
    struct node* new_node = malloc(sizeof(struct node));
    struct node *last_node = *head_ref;

    new_node->data = "cow\n";
    new_node->next = NULL;

    while (last_node->next == NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

//deleting 
void delete_list(struct node** head_ref, char* key) {
    struct node* temp = *head_ref, *prev;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct node* head;
    struct node* one = NULL;
    struct node* two = NULL;
    struct node* three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->next = two;
    two->next = three;
    three->next = NULL;
    head = one;

    one->data = "cat\n";
    two->data = "sand\n";
    three->data = "dog\n";   
   
  
   print_list(head);
   printf("\n");
   delete_list(&head,"sand\n");
   print_list(head);

}
