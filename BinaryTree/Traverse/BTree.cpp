#include <stdlib.h>

typedef char Datatype;

typedef struct BTreeNode{
    Datatype data;
    struct BTreeNode* lchild;
    struct BTreeNode* rchild;
} BTree;

BTree* InsertLeftNode(BTree *curr, Datatype x)
{
    if (curr == NULL) return NULL;

    BTree *s, *t;

    t = curr->lchild; // 保存原curr所指节点的左子树指针
    s = (BTree*)malloc(sizeof(BTree));
    s->data = x;
    s->lchild = t;
    s->rchild = NULL;
    curr->lchild = s;

    return s;
}

BTree* InsertRightNode(BTree *curr, Datatype x)
{
    if (curr == NULL) return NULL;

    BTree *s, *t;

    t = curr->rchild; // 保存原curr所指节点的右子树指针
    s = (BTree*)malloc(sizeof(BTree));
    s->data = x;
    s->rchild = t;
    s->lchild = NULL;
    curr->rchild = s;

    return s;
}

BTree* CreateTree()
{
    /* Construct a binary tree as below:
         A
      B     C
    D     E   F
      G
    */

    BTree *root = (BTree *)malloc(sizeof(BTree));
    root->data = 'A';
    root->lchild = NULL;
    root->rchild = NULL;

    BTree *t = InsertLeftNode(root, 'B');
    t = InsertLeftNode(t, 'D');
    InsertRightNode(t, 'G');

    BTree *c = InsertRightNode(root, 'C');
    InsertLeftNode(c, 'E');
    InsertRightNode(c, 'F');

    return root;
}