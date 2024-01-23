#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int);
struct node* left_insert(struct node*, int );
struct node* right_insert(struct node* , int );
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int main()
{
    struct node* root=createnode(3);
    left_insert(root,5);
    right_insert(root,7);
    left_insert(root->left,8);
    printf("Inorder ");
    inorder(root);
    printf("\nPreorder ");
    preorder(root);
    printf("\nPostorder ");
    postorder(root);
}
struct node* createnode(value)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=value;
    return new_node;
}
struct node* left_insert(struct node* root,int value)
{
    root->left=createnode(value);
    return root->left;
}
struct node* right_insert(struct node* root,int value)
{
    root->right=createnode(value);
    return root->right;
}
void inorder(struct node* root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d->",root->data);
    }
}