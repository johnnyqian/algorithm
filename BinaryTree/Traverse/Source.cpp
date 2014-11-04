#include <stdio.h>
#include <stdlib.h>
#include "Btree.cpp"

#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void visit(Datatype x)
{
    printf("%c\t", x);
}

// 前序，递归
void preOrder_recursion(BTree *curr)
{
    if (curr)
    {
        visit(curr->data);
        preOrder_recursion(curr->lchild);
        preOrder_recursion(curr->rchild);
    }
}

// 中序，递归
void inOrder_recursion(BTree *curr)
{
    if (curr)
    {
        inOrder_recursion(curr->lchild);
        visit(curr->data);
        inOrder_recursion(curr->rchild);
    }
}

// 后序，递归
void postOrder_recursion(BTree *curr)
{
    if (curr)
    {
        postOrder_recursion(curr->lchild);
        postOrder_recursion(curr->rchild);
        visit(curr->data);
    }
}

// 使用非递归时，有两种大的策略，一种是模拟递归，一路向左或向右走到底；
// 另外一种是边输出边处理，根据求解问题的特点设计堆栈的循环机构算法。
// 这两种思路也是所有的递归程序借助堆栈转换成循环结构的非递归算法的两大途径。

// 1. 模拟递归
void preOrder1(BTree *root)
{
    if (!root) return;

    BTree *p;
    stack<BTree*> stack;

    p = root;
    while (!stack.empty() || p)
    {
        // 左走到底
        while (p)
        {
            visit(p->data);

            stack.push(p);
            p = p->lchild;
        }

        p = stack.top();
        stack.pop();

        p = p->rchild;
    }
}

void inOrder1(BTree *root)
{
    if (!root) return;

    BTree *p;
    stack<BTree*> stack;

    p = root;
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
        visit(p->data);

        p = p->rchild;
    }
}

void postOrder1(BTree *root)
{
    if (!root) return;

    // 非递归的后序遍历要比前序和中序复杂些，每个节点需要被访问两次，需要额外的空间来保存这个信息
    BTree *p;
    bool isFirstAccess;
    stack<pair<BTree*, bool>> stack;

    p = root;
    while (!stack.empty() || p)
    {
        // 左走到底
        while (p)
        {
            stack.push(make_pair(p,1));
            p = p->lchild;
        }

        p = stack.top().first;
        isFirstAccess = stack.top().second;
        stack.pop();

        if (isFirstAccess) //第一次访问时，转向同层右结点
        {
            stack.push(make_pair(p, 0)); // 当前节点重新入栈，且将其访问标识置为0
            p = p->rchild;
        }
        else
        {
            visit(p->data);
            p = NULL;
        }
    }
}

// 2. 边输出边处理
void preOrder2(BTree *root)
{
    if (!root) return;

    BTree *t;
    stack<BTree*> stack;

    stack.push(root);
    while (!stack.empty())
    {
        t = stack.top();
        stack.pop();

        visit(t->data);
        // 注意左右子树的入栈的顺序
        if (t->rchild)
            stack.push(t->rchild);
        if (t->lchild)
            stack.push(t->lchild);
    }
}

void inOrder2(BTree *root)
{
    if (!root) return;

    BTree *t;
    bool isFirstAccess;
    stack<pair<BTree*, bool>> stack;

    stack.push(make_pair(root, 1));
    while (!stack.empty())
    {
        t = stack.top().first;
        isFirstAccess = stack.top().second;
        stack.pop();

        if (isFirstAccess)
        {
            // 注意入栈的顺序
            if (t->rchild)
                stack.push(make_pair(t->rchild, 1));
            stack.push(make_pair(t, 0)); // 当前节点重新入栈，且将其访问标识置为0
            if (t->lchild)
                stack.push(make_pair(t->lchild, 1));
        }
        else
        {
            visit(t->data);
        }
    }
}

void postOrder2(BTree *root)
{
    if (!root) return;

    BTree *t;
    bool isFirstAccess;
    stack<pair<BTree*, bool>> stack;

    stack.push(make_pair(root, 1));
    while (!stack.empty())
    {
        t = stack.top().first;
        isFirstAccess = stack.top().second;
        stack.pop();

        if (isFirstAccess)
        {
            // 注意入栈的顺序
            stack.push(make_pair(t, 0)); // 当前节点重新入栈，且将其访问标识置为0
            if (t->rchild)
                stack.push(make_pair(t->rchild, 1));
            if (t->lchild)
                stack.push(make_pair(t->lchild, 1));
        }
        else
        {
            visit(t->data);
        }
    }
}

// level order
void levelOrder(BTree *root)
{
    BTree *t;
    queue<BTree*> queue;

    queue.push(root);
    while (!queue.empty())
    {
        t = queue.front();
        queue.pop();

        visit(t->data);
        // 注意左右子树的入队列的顺序
        if (t->lchild)
            queue.push(t->lchild);
        if (t->rchild)
            queue.push(t->rchild);
    }
}

int main()
{
    BTree *root = CreateTree();

    // preorder
    printf("PreOrder:\n");
    preOrder_recursion(root);
    printf("\n");
    preOrder1(root);
    printf("\n");
    preOrder2(root);
    printf("\n\n");

    // inorder
    printf("InOrder:\n");
    inOrder_recursion(root);
    printf("\n");
    inOrder1(root);
    printf("\n");
    inOrder2(root);
    printf("\n\n");

    // postorder
    printf("PostOrder:\n");
    postOrder_recursion(root);
    printf("\n");
    postOrder1(root);
    printf("\n");
    postOrder2(root);
    printf("\n\n");

    // level order
    printf("LevelOrder:\n");
    levelOrder(root);
    printf("\n\n");

    return 0;
}