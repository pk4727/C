#include <stdio.h>
#include <stdlib.h>
struct node
{

    int data;
    struct node *next;
};
void insertAtBegining(struct node **head, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}
void insertAfter(struct node *prev_node, int new_data)
{

    if (prev_node == NULL)
    {

        printf("previous node cant be null");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
//insertion of node 
void insertAtEnd(struct node **head, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
//deletion of node
void deletenode(struct node**head,int key)
{
    struct node*temp=*head,*prev;
    if(temp!=NULL && temp->data==key)
    {
        *head=temp->next;
        free(temp);
        return;
    }
while(temp != NULL&& temp->data !=key)
{
prev=temp;
temp=temp->next;
}
if(temp==NULL)
return ;
else{
prev->next = temp->next;
free(temp);
}
}
//searching a node
int searchnode(struct node**head,int key)
{
   struct node*p=*head;
   while(p!=NULL){
   if(p->data==key){
   printf("\nsearching data found ");
   return p->data;
   }
  // printf("\nsearching data not found %d\n",p->data);
   p=p->next;
   }
}
//sorting oe linklist
void sortLinkedList(struct node**head)
{
    struct node*p=*head ,*q=NULL;
    int temp;
    
    if(head==NULL)
    {
    return;
    }
    else
    {
        while(p!=NULL)
        {
        q=p->next;
        while(q!=NULL)
        {
            if(p->data>q->data)
            {
            temp=p->data;
            p->data=q->data;
            q->data=temp;   
            }
            q=q->next;
        }
        p=p->next;
        }
    }

}
void printlist(struct node *node)
{
    while (node != NULL)
    {

        printf("%d\n ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node *head = NULL;
    insertAtEnd(&head, 2);
    insertAtBegining(&head, 3);
    insertAtBegining(&head, 4);
    insertAtEnd(&head, 5);
    insertAfter(head->next, 6);
    printf("linklist are:\n ");
    printlist(head);
    printf("\n %d\n",searchnode(&head,3));
    printf("after delete  node :\n ");
    deletenode(&head,3);
    printlist(head);
    printf("\nsearching data is not available %d",searchnode(&head,3));
    sortLinkedList(&head);
    printf("\n sorted list:\n ");
    printlist(head);
}