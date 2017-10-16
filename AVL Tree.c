#include <stdio.h>
#include <stdlib.h>
#include<iostream.h>

struct avltree
{
    int data;
    avltree* right;
    avltree* left;
};
void preOrder(avltree* root)
{
    if(root==NULL)
     return ;
     cout<<root->data;
     preOrder(root->left);
     preOrder(root->right);
}
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int height(avltree* temp)
{
    if(temp==NULL)
    return 0;
    else return 1+max(height(temp->left),height(temp->right));
}
int diff(avltree* temp)
{
int lheight=height(temp->left);
int rheight=height(temp->right);
int b=lheight-rheight;
return b;
}

avltree* getnewnode(int data)
{
     avltree* newnode=new avltree;
     newnode->data=data;
     newnode->left=NULL;
     newnode->right=NULL;
     return newnode;
}
  avltree* llrotation(avltree* node)
{
   avltree* temp;
   temp=node->right;
   node->right=temp->left; 
   temp->left=node;
   return temp;
}
  avltree* rrrotation(avltree* node)
{
   avltree* temp;
   temp=node->left;
   node->left=temp->right;
   temp->right=node;
   return temp;
}
   avltree* lrrotation(avltree* node)
{
    avltree* temp;
    temp=node->left;
    node->left=llrotation(temp);
    return rrrotation(node);
}
  avltree* rlrotation(avltree* node)
{
    avltree* temp;
    temp=node->right;
    node->right=rrrotation(temp);
    return llrotation(node);
}
  avltree* balance(avltree* temp)
{
    int balancefactor=diff(temp);
    if(balancefactor>1)
        {
            if(diff(temp->left)>0)
            temp=rrrotation(temp);
    else
            temp=lrrotation(temp);
        }
     if(balancefactor<-1)
     {
            if(diff(temp->right)>0)
            temp=rlrotation(temp);
    else
            temp=llrotation(temp);
    }
    return temp;
}

  avltree* insert(avltree* root ,int data)
{
    if(root==NULL)
    {
        root=getnewnode(data);
        return root;
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
int main()
{
    int choice;
    avltree* root=NULL;
    cout<<"AVL TREE\n";
    while(1)
    {
     cout<<"\n1.Insert\n2.Display preorder\n3.Exit\n;
     cout<<"Enter your choice\n";
     cin>>choice;
     if(choice==1)
     {
      int data;
      cout<<"Enter data\n";
      cin>>data;
      root=insert(root,data);
      }
     else if(choice==2);
      preOrder(root);
     else if(choice==3)
     break;
     else
     cout<<"You entered wrong choice\n;
     }
    return 0;  
  }
