#include "BSTree.cpp"
#include <iostream>

using namespace std;

void merge(BSTree *s, BSTree *p);

int main()
{
    freopen("Input.txt", "r", stdin);

    BSTree *A, *B;
    A = createTree();
    B = createTree();

    cout << "BST A:\t";
    inorder(A);
    cout << endl;

    cout << "BST B:\t";
    inorder(B);
    cout << endl;

    merge(A, B);

    cout << "Merged BST:\n";
    inorder(A);
    cout << endl;
}

void merge(BSTree *s, BSTree *p)
{
    if (p)
    {
        merge(s, p->lchild);

        BSTree* tmp = (BSTree *)malloc(sizeof(BSTree));
        tmp->data = p->data;
        tmp->lchild = tmp->rchild = NULL;
        insert(s, tmp);

        merge(s, p->rchild);
    }
}