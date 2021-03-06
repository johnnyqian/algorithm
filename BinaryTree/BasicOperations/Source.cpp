﻿#include <stdio.h>
#include <math.h>
#include "Btree.cpp"

#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int count_tree(BTree *root);
int height_tree(BTree *root);
int diameter_tree(BTree *root);
bool is_balanced_tree(BTree *root);
bool is_same_tree(BTree *p, BTree *q);
bool is_complete_binary_tree(BTree *root);
bool is_BST(BTree *root);
BTree* clone(BTree *p);
BTree* mirror(BTree *p);
void destroy(BTree* &p);

int main()
{
    BTree *root = CreateTree();

    // count tree node
    printf("Tree Node numbers:\n");
    printf("%d\n", count_tree(root));
    printf("\n");

    // calculate the height of the tree
    printf("Tree Height:\n");
    printf("%d\n", height_tree(root));
    printf("\n");

    // calculate the diameter of the tree
    printf("Tree Diameter:\n");
    printf("%d\n", diameter_tree(root));
    printf("\n");

    // judge whether is balanced tree 
    printf("Is Balanced Tree:\n");
    printf("%d\n", is_balanced_tree(root));
    printf("\n");

    // check whether two binary trees are equal or not
    printf("Is Same Tree:\n");
    BTree *A = CreateTree();
    BTree *B = CreateTree();
    InsertRightNode(B, 'X');
    printf("%d\n", is_same_tree(root, A));
    printf("%d\n", is_same_tree(A, B));
    printf("\n");

    // check whether is complete binary tree
    printf("Is Complete Binary Tree:\n");
    printf("%d\n", is_complete_binary_tree(root));
    InsertRightNode(root->lchild, 'H');
    InsertLeftNode(root->lchild->lchild, 'I');
    printf("%d\n", is_complete_binary_tree(root));
    printf("\n");

    // check whether is binary search tree
    printf("Is Binary Search Tree:\n");
    printf("%d\n", is_BST(root));
    BTree *bst = CreateBSTree();
    printf("%d\n", is_BST(bst));
    printf("\n");

    // clone a binary tree
    printf("Clone a Binary Tree:\n");
    preOrder_recursion(root);
    printf("\n");
    preOrder_recursion(clone(root));
    printf("\n\n");

    // mirror a binary tree
    printf("Mirror a Binary Tree:\n");
    root = CreateTree();
    preOrder_recursion(root);
    printf("\n");
    preOrder_recursion(mirror(root));
    printf("\n\n");

    // destroy a binary tree
    printf("Destroy a Binary Tree:\n");
    destroy(root);
    printf("Done.\n");

    return 0;
}

// count tree node
int count_tree(BTree *root)
{
    if (root)
        return count_tree(root->lchild) + count_tree(root->rchild) + 1;
    else
        return 0;
}

// calculate the height of the tree
int height_tree(BTree *root)
{
    if (root)
        return max(height_tree(root->lchild), height_tree(root->rchild)) + 1;
    else
        return 0;
}

// calculate the diameter of the tree
// 树的直径不一定经过根节点，需要以每一个节点为根节点进行计算，取最长的
int diameter_tree(BTree *root)
{
    int diameter = 0;
    if (root)
    {
        diameter = max(diameter, height_tree(root->lchild) + height_tree(root->rchild));

        diameter_tree(root->lchild);
        diameter_tree(root->rchild);
    }

    return diameter;
}

// check whether is balanced tree
bool is_balanced_tree(BTree* root)
{
    return (root == NULL)
        || (abs(height_tree(root->lchild) - height_tree(root->rchild)) <= 1)
        && is_balanced_tree(root->lchild)
        && is_balanced_tree(root->rchild);
}

// check whether two binary trees are equal or not
// two binary trees are considered equal if they are structurally identical and the nodes have the same value.
bool is_same_tree(BTree *p, BTree *q)
{
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;

    return (p->data == q->data) && is_same_tree(p->lchild, q->lchild) && is_same_tree(p->rchild, q->rchild);
}

// check whether is complete binary tree
// 层次遍历二叉树，左右节点都入队列。若出队列的结点为空，若其后出队列的结点都为空，则为完全二叉树，否则不是
bool is_complete_binary_tree(BTree *root)
{
    if (!root) return true;

    BTree *t;
    queue<BTree*> queue;
    queue.push(root);

    bool hasNullNode = false;
    while (!queue.empty())
    {
        t = queue.front();
        queue.pop();

        if (!t)
            hasNullNode = true;
        else if (hasNullNode) return false;
        else
        {
            // do not check whether left child or right child is NULL or not
            queue.push(t->lchild);
            queue.push(t->rchild);
        }
    }

    return true;
}

// check whether is binary search tree
// 根据中序遍历序列是否升序来判断
bool is_BST(BTree *root)
{
    if (!root) return true;

    BTree *p = root;
    BTree *pre = NULL;
    stack<BTree*> stack;

    while (!stack.empty() || p)
    {
        // 左走到底
        while (p)
        {
            stack.push(p);
            p = p->lchild;
        }

        p = stack.top();
        stack.pop();

        if (pre && p->data <= pre->data)
            return false;

        pre = p;
        p = p->rchild;
    }

    return true;
}

// clone a binary tree
BTree* clone(BTree *p)
{
    if (!p) return NULL;

    BTree *temp = (BTree*)malloc(sizeof(BTree));
    temp->data = p->data;
    temp->lchild = clone(p->lchild);
    temp->rchild = clone(p->rchild);
    return temp;
}

// mirror a binary tree
BTree* mirror(BTree *p)
{
    if (!p) return NULL;

    BTree* lmirror = mirror(p->lchild);
    BTree* rmirror = mirror(p->rchild);

    p->lchild = rmirror;
    p->rchild = lmirror;

    return p;
}

// destroy a binary tree
// traverse the tree with post order
void destroy(BTree* &p)
{
    if (p)
    {
        destroy(p->lchild);
        destroy(p->rchild);
        free(p);
        p = NULL;
    }
}