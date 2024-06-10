#include <stdio.h>
#include <stdlib.h>

struct node{
  int value;
  struct node* next;
};


typedef struct node node_t;                                     //This typedef is to define the node_t variable 

void printlist (node_t *head)                                   //This function is to print the enlisted variables 
{
    node_t *temp = head;
    while (temp!=NULL)
    {
      printf("%d - ",temp->value);
      temp=temp->next;
    }
    printf("\n");
}

node_t *create_new_node(int value){                             //This function is to create a new node using memory allocation//
  node_t *result =  malloc(sizeof(node_t));
  result->value = value;
  result->next=NULL;
  return result;
}

node_t *insert_at_head(node_t *head, node_t *node_to_insert){  //This function is to insert a new node to the head of the list //
  node_to_insert->next = head;
  return node_to_insert; 

}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode){
                                                                          //This function is to insert a new node to the desired position
  newnode->next = node_to_insert_after->next;                         
  node_to_insert_after->next = newnode;

}

void delete_node(node_t** head, int position)           //This function is to delete a node from the linked list
{
    node_t* temp;
    node_t* prev;


    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->next;
            free(temp); 
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
 
                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

 int getCount(node_t* head)           //This function is to count the node in the list
 {
  int count=0;
  node_t* current = head;
  while(current!=NULL)  {
    count++;
    current = current->next;
  }
  return count;
 }

static void reverse(node_t** head_ref)    //This function is to reverse the list
{
  node_t* prev = NULL;
  node_t* current = *head_ref;
  node_t* next = NULL;

  while(current!=NULL){
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
}



int search_Element(node_t* head,int item)       //This function is to search an element in the linked list
{
  node_t *current = head;
  int index = 0;

    while (current != NULL)
    {
      if (current -> value == item)
      {
        return index;
      }
      current = current -> next;
      index++;
    }
    return -1;
}

int main(){
    node_t *head;
    node_t *tmp;
    int item;

    //node_t n1,n2,n3,n4;
    // printf("\nEnter the 1st value:");
    // scanf("%d",&n1.value);
    // printf("\nEnter the 2nd value:");
    // scanf("%d",&n2.value);
    // printf("\nEnter the 3rd value:");
    // scanf("%d",&n3.value);
    // printf("\nEnter the 4th value:");
    // scanf("%d",&n4.value);
    
    // n1 = malloc(sizeof(node_t));
    // n1->value=75;
    // n2.value=100;
    // n3.value=59;
    // n4.value=1;

    // Now we link them up
    //We link up here as [n1 -> n2 -> n3 -> n4]
    // head = n1;
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = NULL;
    
    tmp = create_new_node(3);                          //A new node is created with value of 32
    head = tmp;
    
    tmp = create_new_node(32);                          //A new node is created with value of 32
    tmp -> next = head;
    head = tmp;

    tmp = create_new_node(5);
    tmp->next = head;
    head = tmp;

    tmp = create_new_node(12);
    tmp->next = head;
    head = tmp;
    
    tmp = create_new_node(59);
    head = insert_at_head(head,tmp);                    //A new head is added t as value of node is 59 
  
    insert_after_node(tmp, create_new_node(4));         //A new node is inserted after 5
    
    tmp = create_new_node(90);
    tmp->next = head;
    head = tmp;
    
     
    printf("=============================================\n");


    printf("Enter an element to search an element:");
    scanf("%d",&item);
    int index = search_Element(head,item);

    if (index == -1)
    {
      printf("\nItem not found\n");
    }
    else
    {
      printf("\nItem found at position:%d\n",index+1);  
    }
    

    printf("=============================================\n");

        
    printf("Linked List is:\n");
    printlist(head);


    printf("=============================================\n");


    printf("Linked List before deletion:\n");
    printlist(head);
    printf("Count before deletion: %d\n",getCount(head));
    delete_node(&head,7);


    printf("=============================================\n");
    

    printf("Linked List after deletion:\n");
    printlist(head);
    printf("Count after deletion: %d\n",getCount(head));


    printf("=============================================\n");


    printf("Reversed list is :\n");
    reverse(&head);
    printlist(head);
    

    printf("=============================================\n");

return 0;
}
