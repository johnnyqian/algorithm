/*
���ô�ͷ���ĵ�����
*/
#include <stdio.h>
#include <stdlib.h>

#include <stack>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* Next;
}SLNode;

void print(SLNode* head)
{
    SLNode *p = head;

    while (p->Next)
    {
        p = p->Next;
        printf("%d\t", p->data);
    }
    printf("\n");
}

SLNode* reverse(SLNode* head)
{
    SLNode *curr = head->Next; // ��һ�����ݽڵ�
    if (!curr || !curr->Next)
        return head;

    SLNode *pre = NULL, *tmp;
    while (curr)
    {
        tmp = curr;
        curr = curr->Next;
        tmp->Next = pre;
        pre = tmp;
    }
    head->Next = pre; // ��ͷ���ָ�����ú�ĵ�һ���ڵ�

    return head;
}

SLNode* reverse_recursively_internal(SLNode* pre, SLNode* curr)
{
    SLNode *next = curr->Next;
    curr->Next = pre;

    if (next)
        return reverse_recursively_internal(curr, next);
    else
        return curr;
}

SLNode* reverse_recursively(SLNode* head)
{
    SLNode *curr = head->Next; // ��һ�����ݽڵ�
    if (!curr || !curr->Next)
        return curr;

    head->Next = reverse_recursively_internal(NULL, curr);

    return head;
}

SLNode* reverse_stack(SLNode* head)
{
    SLNode *curr = head->Next; // ��һ�����ݽڵ�
    if (!curr || !curr->Next)
        return curr;

    stack<SLNode*> stack;
    while (curr)
    {
        stack.push(curr);
        curr = curr->Next;
    }

    head->Next = curr = stack.top(); // ��ͷ���ָ�����ú�ĵ�һ���ڵ�
    stack.pop();

    SLNode *tmp;
    while (!stack.empty())
    {
        tmp = stack.top();
        stack.pop();

        curr->Next = tmp;
        curr = tmp;
    }
    curr->Next = NULL;

    return head;
}

void main()
{
    int t;
    SLNode *head, *p, *tmp;

    head = (SLNode*)malloc(sizeof(SLNode));
    head->Next = NULL;
    p = head;

    freopen("Input.txt", "r", stdin);
    while (scanf("%d", &t) != EOF)
    {
        tmp = (SLNode*)malloc(sizeof(SLNode));
        tmp->data = t;

        p->Next = tmp;
        p = p->Next;
    }
    p->Next = NULL;

    // 1. use while loop
    print(head);
    head=reverse(head);
    print(head);

    // reset linked list
    head = reverse(head);
    printf("\n");

    // 2. use recursion
    print(head);
    head = reverse_recursively(head);
    print(head);

    // reset linked list
    head = reverse_recursively(head);
    printf("\n");

    // 3. use stack
    print(head);
    head = reverse_stack(head);
    print(head);
}