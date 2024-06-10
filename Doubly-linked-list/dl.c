#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node* next;
    struct Node* prev;

};

typedef struct Node Node_t;

void printlist (Node_t *head)                                   //This function is to print the enlisted variables 
{
    Node_t *temp = head;
    while (temp!=NULL)
    {
      printf("%d <-> ",temp->data);
      temp=temp->next;
      if (temp == NULL)
      {
        printf("NULL");
      }      
    }
    printf("\n");
}

void push(Node_t **head_ref, int new_data)
{
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if (new_node == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(1);
    }

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    Node_t *last_node = *head_ref;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    new_node->prev = last_node;
}

Node_t* insert_after(Node_t* prev_node,int new_data)
{
    if(prev_node==NULL)
    {
        printf("The given node cannot be added");
        exit(1);
    }

    Node_t* new_node = malloc(sizeof(Node_t)); 

    if(new_node == NULL)
    {
         printf("Memory Allocation failed\n");
         exit(1);
    }

    new_node -> data = new_data;
    new_node -> next = prev_node -> next;
    new_node ->prev = prev_node;

    if(new_node -> next != NULL)
    {
        new_node -> next -> prev = new_node; 
    }

    prev_node -> next = new_node;
    return new_node;
}

void delete_node(Node_t** head_ref,Node_t* del)
{
    if(*head_ref == NULL||del == NULL) 
      return;
    
    if(*head_ref == del)
      *head_ref = del->next;

    if (del->next != NULL)
      del->next->prev = del->prev;

    if (del->next != NULL)
      del->prev->next = del->next;
    
    free(del);
    return;
}

void reverse_list(Node_t ** head_ref)
{

  Node_t* temp = NULL;
  Node_t* current = *head_ref;

  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  
  if (temp != NULL)
  {
    *head_ref = temp  ;
  }
  
}

int find_size(Node_t* node)
{
  int size = 0;
  while (node != NULL)
  {
    size++;
    node = node->next;
  }
  return size;
}

int main() 
{

    Node_t* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printf("========================================\n");

    printf("Doubly linked list :\n");
    
    printlist(head);

    printf("========================================\n");
    
    printf("Inserting a node:\n");
    
    insert_after(head->next->next->next, 5);

    printlist(head);

    printf("Size of linked list after adding is:%d\n",find_size(head));

    printf("========================================\n");
    
    printf("Deleting a node:\n");

    delete_node(&head,head->prev);

    printlist(head);

    printf("========================================\n");

    printf("Reversed list:\n");

    reverse_list(&head);

    printlist(head);

    printf("Size of the doubly linked list is :%d\n",find_size(head));

    printf("========================================\n");
    
    return 0;

}
