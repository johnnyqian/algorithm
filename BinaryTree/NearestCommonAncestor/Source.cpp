#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;
typedef struct BTreeNode{
    Datatype data;
    struct BTreeNode *lchild, *rchild, *parent;
} BTree;

void print(BTree* result);
BTree* findNCA(BTree* p, BTree* q);
int findNCA2(BTree* root, BTree* p, BTree* q, BTree** result);
BTree* insertRightNode(BTree *curr, Datatype x);
BTree* insertLeftNode(BTree *curr, Datatype x);

int main()
{
    /* Construct a binary tree as below:
         A
      B     C
    D     E   F
      G
    */
    BTree *A, *B, *C, *D, *E, *F, *G, *result;

    A = (BTree *)malloc(sizeof(BTree));
    A->data = 'A';
    A->lchild = NULL;
    A->rchild = NULL;
    A->parent = NULL;

    B = insertLeftNode(A, 'B');
    C = insertRightNode(A, 'C');
    D = insertLeftNode(B, 'D');
    G = insertRightNode(D, 'G');
    E = insertLeftNode(C, 'E');
    F = insertRightNode(C, 'F');

    printf("D, E Ancestor:\t");
    result = findNCA(D, E);
    print(result);
    printf("D, E Ancestor:\t");
    findNCA2(A, D, E, &result);
    print(result);

    printf("D, G Ancestor:\t");
    result = findNCA(D, G);
    print(result);
    printf("D, G Ancestor:\t");
    findNCA2(A, D, G, &result);
    print(result);

    printf("A, G Ancestor:\t");
    result = findNCA(A, G);
    print(result);
    printf("A, G Ancestor:\t");
    findNCA2(A, A, G, &result);
    print(result);

    return 0;
}

// 使用Parent指针，即如果二叉树的节点中定义了父指针域
BTree* findNCA(BTree* p, BTree* q)
{
    while (p)
    {
        p = p->parent;

        BTree* temp = q;
        while (temp)
        {
            if (p == temp->parent)
                return p;
            temp = temp->parent;
        }
    }

    return NULL;
}

// TODO, 使用2条链表，以空间换时间

// 不使用Parent指针
// 返回root为根的树种包含p,q两个节点中节点的数目:0,1,2
int findNCA2(BTree* root, BTree* p, BTree* q, BTree** result)
{
    if (!root) return 0;
    if (root == p || root == q) return 1;

    int left = findNCA2(root->lchild, p, q, result);
    if (left == 2) return 2;

    int right = findNCA2(root->rchild, p, q, result);
    if (right == 2) return 2;

    if(left + right == 2) *result = root;

    return left + right;
}

BTree* insertLeftNode(BTree *curr, Datatype x)
{
    if (curr == NULL) return NULL;

    BTree *s, *t;

    t = curr->lchild; // 保存原curr所指节点的左子树指针
    s = (BTree*)malloc(sizeof(BTree));
    s->data = x;
    s->lchild = t;
    s->rchild = NULL;
    s->parent = curr;
    curr->lchild = s;

    return s;
}

BTree* insertRightNode(BTree *curr, Datatype x)
{
    if (curr == NULL) return NULL;

    BTree *s, *t;

    t = curr->rchild; // 保存原curr所指节点的右子树指针
    s = (BTree*)malloc(sizeof(BTree));
    s->data = x;
    s->rchild = t;
    s->lchild = NULL;
    s->parent = curr;
    curr->rchild = s;

    return s;
}

void print(BTree* result)
{
    if (result)
        printf("%c\n", result->data);
    else
        printf("NULL\n");
}