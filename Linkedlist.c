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
   for(i=0;i<n;i++)
   {
       scanf("%d",&x);
       insert(x);
       print();
   }
    return 0;
}
