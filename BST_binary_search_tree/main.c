/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct Btree
{
    int data;
    struct Btree *right;//pointing to right child
    struct Btree *left;// pointing to left child
};
typedef struct Btree node;
//node *root=NULL;
//preorder root->left->right//
//inorder left->root->right//
//postorder left->right->root//

node *findmin(node *r)// funtion to find the node having the data minimum;
{
    node *cur=r;
    while(cur->left!=NULL)
    cur=cur->left;
    return cur;

}
node *insert(node *root)
{   node *n;
    node *temp;
    n=(node *)malloc(sizeof(node));
    printf("enter the element\n");
    scanf("%d",&n->data);
    n->left=n->right=NULL;
    if(root==NULL)
        {
        root=n;
        return root;
        }
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data>n->data)
        {
            if(temp->left==NULL)
            {temp->left=n;return root;}//after first node;
            temp=temp->left;
        }
        else if(temp->data<n->data)
        {
            if(temp->right==NULL)
            {temp->right=n;return root;}//after first node;
            temp=temp->right;
        }
    }
return root;
}
void preorder(node *root)//if root will be global it wont work;
{   node *t1=root;
    if(t1!=NULL)
    {
        printf("%d\t",t1->data);
        preorder(t1->left);
        preorder(t1->right);
    }
}

void postorder(node * root)//root should be local;
{node *t1=root;
    if(t1!=NULL)
    {

        postorder(t1->left);
        postorder(t1->right);
        printf("%d\t",t1->data);
    }
}
void inorder(node * root)
{node *t1=root;
    if(t1!=NULL)
    {

        inorder(t1->left);
        printf("%d\t",t1->data);
        inorder(t1->right);

    }
}
node* delete(node * root,int ele)// return type must be node;
{
    if(root==NULL)
    {
        printf("empty\n");
        return root;

    }
    if(ele<root->data)
        root->left=delete(root->left,ele);
    else if(ele>root->data)
            root->right=delete(root->right,ele);
    else//if element found
    {
        if(root->left==NULL)//for single child
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)//for single child
        {
            node *temp=root->left;
            free(root);
            return temp;

        }
        node *temp=findmin(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
        return root;
}

int main()
{   int ch,ele;
node *root=NULL;
    printf("\n1:insert\n2:inorder\n3:preorder\n4:postorder\n5:delete\n6:exit\n");
do
{
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:root=insert(root);
        break;
        case 2 :inorder(root);
        break;
        case 3: preorder(root);
        break;
        case 4: postorder(root);
        break;
        case 5: printf("enetr the element\n");
        scanf("%d",&ele);
        root=delete(root,ele);
        break;
        case 6: exit(0);

    }
}while(1);
    return 0;
}

