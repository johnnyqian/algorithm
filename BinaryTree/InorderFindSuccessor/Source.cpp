#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;
typedef struct BTreeNode{
    Datatype data;
    struct BTreeNode* lchild;
    struct BTreeNode* rchild;
    struct BTreeNode* parent;
} BTree;

void inOrderRecursion(BTree *curr, bool outPutNext);
BTree* insertRightNode(BTree *curr, Datatype x);
BTree* insertLeftNode(BTree *curr, Datatype x);
BTree* findNext(BTree* curr);

int main()
{
    /* Construct a binary tree as below:
         A
      B     C
    D     E   F
      G
    */
    BTree *A, *B, *C, *D, *E, *F, *G;

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

    // inOrder
    printf("InOrder:\n");
    inOrderRecursion(A, false);
    printf("\n\n");
    inOrderRecursion(A, true);

    return 0;
}

BTree* findNext(BTree* curr)
{
    BTree *p;
    p = curr;

    if (p->rchild) // ���������������ݹ��ҵ�����������ߵĽڵ�
    {
        p = p->rchild;
        while (p->lchild)
        {
            p = p->lchild;
        }

        return p;
    }
    else if (p->parent) // �������丸�ڵ����
    {
        BTree* parent = p->parent;
        while (parent && parent->rchild == p) // ���ϵݹ��ҵ���һ����Ϊ�����������Ƚڵ㣬�����ҵ����ڵ�ĸ��ڵ㣨NULL��
        {
            p = parent;
            parent = p->parent;
        }

        return parent;
    }
    else // ��ǰ�ڵ�Ϊ���ڵ㣬��û������������ʱ�������˻�Ϊ����
    {
        return NULL;
    }
}

void inOrderRecursion(BTree *curr, bool outPutNext)
{
    if (curr)
    {
        inOrderRecursion(curr->lchild, outPutNext);
        printf("%c  ", curr->data);
        if (outPutNext)
        {
            BTree* next = findNext(curr);
            if (next)
            {
                printf("->  %c\n", next->data);
            }
            else
            {
                printf("->  NULL\n");
            }
        }
        inOrderRecursion(curr->rchild, outPutNext);
    }
}

BTree* insertLeftNode(BTree *curr, Datatype x)
{
    if (curr == NULL) return NULL;

    BTree *s, *t;

    t = curr->lchild; // ����ԭcurr��ָ�ڵ��������ָ��
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

    t = curr->rchild; // ����ԭcurr��ָ�ڵ��������ָ��
    s = (BTree*)malloc(sizeof(BTree));
    s->data = x;
    s->rchild = t;
    s->lchild = NULL;
    s->parent = curr;
    curr->rchild = s;

    return s;
}