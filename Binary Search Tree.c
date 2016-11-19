// Binary Tree
// insertion,depth order Traversal,minimum and maximum element in BST,Height of BST.
#include <stdio.h>
#include <stdlib.h>
struct bstnode
{
    int data;
    struct bstnode* right;
    struct bstnode* left;
};
int getnewnode(int data)
{
     struct bstnode* newnode=( struct bstnode*)malloc(sizeof(struct bstnode));
     newnode->data=data;
     newnode->left=NULL;
     newnode->right=NULL;
     return newnode;
}
struct bstnode* insert( struct bstnode* root ,int data)
{
    struct bstnode* temp;
    if(root==NULL)
    {
        temp=getnewnode(data);
        return temp;
    }
    else if(data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    printf("AJ Rocks \n");
return root;
}
int search(struct bstnode* root,int data)
{
    if(root==NULL){
        printf("hmse bakchodi");
    }
    else if(root->data==data){
      printf("%d",data);
    }
    else if(data<=root->data){
        search(root->left,data);
    }

         else if(data>root->data){
         search(root->right,data);
    }
}
int max(struct bstnode* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    printf("%d\n",root->data);


}
int min(struct bstnode* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    printf("%d\n",root->data);


}
void inOrder(struct bstnode* root)
{
    if(root!=NULL){

  inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);

}
}
void preOrder(struct bstnode* root)
{
    if(root!=NULL){


        printf("%d ", root->data);
         preOrder(root->left);
        preOrder(root->right);

}
}
void postOrder(struct bstnode* root)
{
    if(root!=NULL){

  postOrder(root->left);

        postOrder(root->right);
         printf("%d ", root->data);

}
}
int max1(int r,int h){
if(r>h){
    return r;
}
else
    return h;
}
int bstheight(struct bstnode* temp){
    int h;
if(temp==0)
{
    return 0;
}
else {
    int l=bstheight(temp->left);
    int r=bstheight(temp->right);
    int maxht=max1(l,r);
    h=maxht+1;
}

return h;
}
int main()
{
    int r;
   struct bstnode* root=NULL;
    root=insert(root,20);
    insert(root,10);
    insert(root,15);
    insert(root,25);
    insert(root,30);
    insert(root,5);
    insert(root,22);
    printf("***********BINARY TREE************** \n");
    //insert(root,24);
   search(root,25);
   printf("\t");
   search(root,30);
     printf("\n");
   inOrder(root);
   printf("\n");
   preOrder(root);
     printf("\n");
   postOrder(root);
  r=bstheight(root);
  printf("\n");
   printf("%d",r);
   printf(" \n $$$$$ DEVELOPED BY AJ $$$$$");


    return 0;
}

