#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* head;
void insert(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    head=temp;

}
void reverse()
{
  struct node* prev;
  struct node* next;
  struct node* current=head;
  prev=NULL;
  while(current!=NULL)
  {
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
  }

  head=prev;


}
void print()
{
    struct node* temp1=head;
    printf("list is");
    while(temp1 !=0)
    {
        printf("%d",temp1->data);
        printf("\n");
        temp1=temp1->next;
    }
    printf("\n");

}

int main()
{
   int n,i,x;
   printf("how many numbers");
   scanf("%d",&n);
   printf("Enter numbers in reverse order we will correct it for you.");
   for(i=0;i<n;i++)
   {
       scanf("%d",&x);
       insert(x);

   }

   reverse();
   print();
    return 0;
}
