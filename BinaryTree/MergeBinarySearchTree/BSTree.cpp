#include <iostream>

using namespace std;

typedef int DataType;
typedef struct BSTreeNode{
    DataType data;
    struct BSTreeNode *lchild, *rchild;
} BSTree;

void insert(BSTree* curr, BSTree* tmp);

BSTree* createTree()
{
    BSTree *root, *tmp;
    root = NULL;

    int x;
    while (cin >> x && x!=-1)
    {
        tmp = (BSTree *)malloc(sizeof(BSTree));
        tmp->data = x;
        tmp->lchild = tmp->rchild = NULL;

        if (!root)
            root = tmp;
        else
            insert(root, tmp);
    }
    return root;
}

void insert(BSTree* curr, BSTree* tmp)
{
    if (tmp->data < curr->data)
    {
        if (!curr->lchild)
            curr->lchild = tmp;
        else
            insert(curr->lchild, tmp);
    }
    else if (tmp->data > curr->data)
    {
        if (!curr->rchild)
            curr->rchild = tmp;
        else
            insert(curr->rchild, tmp);
    }
    else
    {
        // duplicate value is not allowed in binary search tree
        cerr << "duplicate value is not allowed!" << endl;
        exit(1);
    }
}

// traverse with inorder
void inorder(BSTree *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        cout << p->data << "\t";
        inorder(p->rchild);
    }
}