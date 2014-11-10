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

    BTree *b = InsertLeftNode(root, 'B');
    BTree *d= InsertLeftNode(b, 'D');
    InsertRightNode(d, 'G');

    BTree *c = InsertRightNode(root, 'C');
    InsertLeftNode(c, 'E');
    InsertRightNode(c, 'F');

    return root;
}

BTree* CreateBSTree()
{
    /* Construct a binary search tree as below:
             G
         E         K
      C     F   H     M
        D
    */

    BTree *root = (BTree *)malloc(sizeof(BTree));
    root->data = 'G';
    root->lchild = NULL;
    root->rchild = NULL;

    BTree *e = InsertLeftNode(root, 'E');
    InsertRightNode(e, 'F');
    BTree *c = InsertLeftNode(e, 'C');
    InsertRightNode(c, 'D');

    BTree *k = InsertRightNode(root, 'K');
    InsertLeftNode(k, 'H');
    InsertRightNode(k, 'M');

    return root;
}