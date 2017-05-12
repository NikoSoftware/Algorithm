#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* Init(int val)
{
    struct Node *pNew;
    pNew=(struct Node*)malloc(sizeof(struct Node));
    pNew->left=pNew->right=NULL;
    pNew->data=val;
    return pNew;
}
void Insert(struct Node *node,int val)
{
    struct Node *pNew;
    if(node->data>val)
    {
        if(node->left==NULL)
        {
            pNew=(struct Node *)malloc(sizeof(struct Node));
            pNew->left=pNew->right=NULL;
            pNew->data=val;
            node->left=pNew;
            return;
        }
        else
        Insert(node->left,val);
    }
    else
    {
        if(node->right==NULL)
        {
            pNew=(struct Node *)malloc(sizeof(struct Node));
            pNew->left=pNew->right=NULL;
            pNew->data=val;
            node->right=pNew;
            return;
        }
        else
        Insert(node->right,val);
    }
}
void Show(struct Node *node)
{
    if(node->left!=NULL)
    Show(node->left);
    printf("%d ",node->data);
    if(node->right!=NULL)
    Show(node->right);
}
int main()
{
    int n,val,i;
    struct Node *root;

    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&val);

        root=Init(val);
        for(i=1;i<n;i++)
        {
            scanf("%d",&val);
            Insert(root,val);
        }
        Show(root);
    }

  return 0;

}
