#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

struct BST
{
    int data;
    BST *left;
    BST *right;
};

BST* insert(BST *root, int n)
{
    BST *node=new BST();
    node->data=n;
    node->left=NULL;
    node->right=NULL;

    if(!root)
        root=node;
    else if(n<root->data)
        root->left = insert(root->left, n);
    else
        root->right = insert(root->right, n);

    return root;
}

void postorder(BST *root)
{
    if(!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    BST *root;

    root=NULL;

    int n;

    while(cin>>n)
        root = insert(root, n);

    postorder(root);

    return 0;
}
