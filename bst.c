#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int val)
{
    struct node* root= (struct node*)malloc(sizeof(struct node));
    root->data=val;
    root->right=root->left=NULL;
    return root;
}

struct node *insert(struct node* root, int val)
{
    if(root==NULL)
    {
       return create(val);
    }
    else
    {
        if(val < root->data)
            root->left=insert(root->left,val);
        else if(val> root->data)
            root->right=insert(root->right,val);
    }
    return root;
}

void preorder(struct node *root)
{   
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{   
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void inorder(struct node *root)
{   
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

struct node *min (struct node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node *max(struct node *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

int main(void)
{
    struct node* root = NULL;
    int n,data;

    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&data);
        root = insert(root,data);
    }

    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("preorder: ");
    preorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");

    printf("min: %d and max: %d",min(root)->data,max(root)->data);
    printf("\n");
}
