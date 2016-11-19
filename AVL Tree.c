//Program for construction of "AVL Tree".

#include <stdio.h>
#include <stdlib.h>

struct avltree
{
    int data;
    struct avltree* right;
    struct avltree* left;
};
void preOrder(struct avltree* root)
{
    if(root!=NULL){


        printf("%d ", root->data);
         preOrder(root->left);
        preOrder(root->right);

}
}
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
//yet to discover chamber of secret.
int height(struct avltree* aman)
{
    int h=0;
    if (aman!=NULL)
    {
        int lht=height(aman->left);
        int rht=height(aman->right);
        int maxht=max(lht,rht);
        h=maxht+1;
    }
    return h;
}
int diff(struct avltree* temp)
{
int lheight=height(temp->left);
int rheight=height(temp->right);
int b=lheight-rheight;
return b;
}
//discovered? lol work under progress.
int getnewnode(int data)
{
     struct avltree* newnode=( struct avltree*)malloc(sizeof(struct avltree));
     newnode->data=data;
     newnode->left=NULL;
     newnode->right=NULL;
     return newnode;
}
struct avltree* rrrotation(struct avltree* node)
{
   struct avltree* temp;
   temp=node->right;
   node->right=temp->left; //(this is for the key node transfer between left to right)
   temp->left=node;
   return temp;
}
struct avltree* llrotation(struct avltree* node)
{
   struct avltree* temp;
   temp=node->left;
   node->left=temp->right;
   temp->right=node;
   return temp;
}
struct avltree* lrrotation(struct avltree* node)
{
    struct avltree* temp;
    temp=node->left;
    node->left=rrrotation(temp);
    return llrotation(node);
}
struct avltree* rlrotation(struct avltree* node)
{
    struct avltree* temp;
    temp=node->right;
    node->right=llrotation(temp);
    return rrrotation(node);
}
struct avltree* balance(struct avltree* temp)
{
    int balancefactor=diff(temp);
    if(balancefactor>1)
        {
            if(diff(temp->left)>0)
            temp=llrotation(temp);
    else
            temp=lrrotation(temp);
        }
     if(balancefactor<-1)
     {
            if(diff(temp->right)>0)
            temp=rlrotation(temp);
    else
            temp=rrrotation(temp);
    }
    return temp;
}

struct avltree* insert( struct avltree* root ,int data)
{
    struct avlnode* temp;
    if(root==NULL)
    {
        temp=getnewnode(data);
        return temp;
    }
    else if(data<=root->data)
    {
        root->left=insert(root->left,data);
        root=balance(root);
    }
    else
    {
        root->right=insert(root->right,data);
        root=balance(root);
    }
return root;
}
void main(){
    int c,e;
    struct avltree* root=NULL;
    printf(" \t \t \t \t****** AVL TREE ********");

while(c!=3){
    printf(" \n \n 1)Insertion \n 2)Display \n 3)Exit");
    scanf("%d",&c);
    switch(c){

    case 1:
    printf("enter the element");
    scanf("%d",&e);
    root=insert(root,e);
    case 2:
    printf("avl in preorder is");
    preOrder(root);
    }
    }
    return 0;
}



