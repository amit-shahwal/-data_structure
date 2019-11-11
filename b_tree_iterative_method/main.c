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
struct stackk
{
    struct Btree *sdata[40];
    int sp;

}st;
//typedef struct stackk st;
void push(struct Btree * ele )
{   st.sp++;
    st.sdata[st.sp]=ele;
}
struct Btree* pop()
{struct Btree *elep;
elep=st.sdata[st.sp];
st.sp--;
    return elep;
}
typedef struct Btree node;
//node *root=NULL;
//preorder root->left->right//
//inorder left->root->right//
//postorder left->right->root//

node *findmin(node *r)
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
            {temp->left=n;return root;}
            temp=temp->left;
        }
        else if(temp->data<n->data)
        {
            if(temp->right==NULL)
            {temp->right=n;return root;}
            temp=temp->right;
        }
    }
return root;
}
void inorder(node *root)
{   //int t;
    if(root==NULL)
    return;
    while(1)
    {
        if(root!=NULL)

        {
        push(root);
        root=root->left;
        }
        else
        {
            if (st.sp==-1)
            {
                break;
            }
             root=pop();
             printf("%d\t",root->data);
             root=root->right;
        }

    }
}
void postorder(node * root)
{node *t1=root;
    if(t1!=NULL)
    {

        postorder(t1->left);
        postorder(t1->right);
        printf("%d\t",t1->data);
    }
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    push(root);
    while(st.sp!=-1)
    {
        root=pop();
        printf("%d\t",root->data);
        if(root->right!=NULL)
        {
            push(root->right);
        }
        if(root->left!=NULL)
        {
            push(root->left);
        }
    }
}
node* delete(node * root,int ele)
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
    else
    {
        if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
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
void ini()
{
    st.sp=-1;
    return;
}
int main()
{   ini();
    int ch,ele;
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


