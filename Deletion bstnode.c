#include <stdio.h>
#include <stdlib.h>
struct bstnode
{
    int data;
    struct bstnode* right;
    struct bstnode* left;
};
int investigation(struct bstnode* root,int data)
{
    if(data<root->data){
      root->left=investigation(root->left,data);
    }
    else if(data>root->data){
       root->right=investigation(root->right,data);
    }
    else if(data==root->data){
        printf("****** AJ CODE ******* \n \n");
       root= delete1(root);
    }
    return root;
}
int delete1(struct bstnode* root2){
    if(root2->left==NULL&&root2->right==NULL){
            free(root2);
           return NULL;

      }

     else if(root2->right==NULL&&root2->left!=NULL){
        struct bstnode* temp=root2->left;
         free(root2);
        return(temp);
        }

         else if(root2->left==NULL&&root2->right!=NULL){
        struct bstnode* temp1=root2->right;
        free(root2);
        return(temp1);
       }


    else if (root2->left!=NULL&&root2->right!=NULL){

        struct bstnode* temp2=min1(root2->right);
        root2->data=temp2->data;
        root2->right=investigation(root2->right,temp2->data);
        free(temp2);


        return(root2);



    }
    return;

}
int min1(struct bstnode* root3){
    while(root3->left!=NULL){
        root3=root3->left;
    }
    return root3;
}
struct bstnode* getnewnode(int data)
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
       root->left= insert(root->left,data);
    }
    else
    {
       root->right= insert(root->right,data);
    }
return root;
}
int search(struct bstnode* root,int data)
{
    if(root==NULL){
        printf("empty tree,dont be smart");
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
{ if(root!=NULL)
    {

  inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);

}

}
void preOrder(struct bstnode* root)
{
    if(root!=NULL)
    {

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

int main()
{
   struct bstnode* root=NULL;
    root=insert(root,20);
    insert(root,10);
    insert(root,15);
    insert(root,25);
    insert(root,30);
    insert(root,5);
    insert(root,22);
    insert(root,18);
    insert(root,24);
    printf("******** Deletion in Binary Tree ******** \n");
   search(root,25);
   printf("\t \t");
   search(root,30);
     printf("\n \n");
   inOrder(root);
   printf("\n \n");
   preOrder(root);
     printf("\n \n");
   postOrder(root);
    printf("\n \n");
   investigation(root,10);
    preOrder(root);
    printf("\n \n");
    investigation(root,30);
     preOrder(root);
    printf("\n \n");
    investigation(root,15);
     preOrder(root);
     printf("\n \n");
     printf("\n$$$$$$ Developed by AJ $$$$$$ \n");



    return 0;
}

