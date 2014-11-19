#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* Next;
}SLNode;

SLNode* selectNode(SLNode* head, int x)
{
    SLNode* p = head->Next;

    while (p&&p->data != x)
    {
        p = p->Next;
    }

    return p;
}

// x is the entry point of the cycled linked list
SLNode* createCycledLinkedList(int n, int x)
{
    SLNode *head, *p, *tmp;

    head = (SLNode*)malloc(sizeof(SLNode));
    head->Next = NULL;
    p = head;

    for (int i = 1; i <= n; i++)
    {
        tmp = (SLNode*)malloc(sizeof(SLNode));
        tmp->data = i;

        p->Next = tmp;
        p = p->Next;
    }
    p->Next = NULL;

    // set the entry point of the cycled linked list
    p->Next = selectNode(head, x);

    return head;
}

bool hasCycle(SLNode* head, int* ret)
{
    if (head == NULL || head->Next == NULL)
        return false;
    if (head->Next == head)
        return true;

    SLNode *slow, *fast;
    slow = fast = head;

    while (fast && fast->Next)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        if (slow == fast) break;
    }

    if (slow == fast)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->Next;
            fast = fast->Next;
        }
        *ret = fast->data;

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout.setf(ios_base::boolalpha);
    int ret;

    SLNode *head = createCycledLinkedList(10, 6);
    if (hasCycle(head->Next, &ret))
        cout << "Linked list 1 has cycle : true, and the entry point is :" << ret << endl;
    else
        cout << "Linked list 2 has cycle : false" << endl;

    SLNode *head2 = createCycledLinkedList(20, 30);
    if (hasCycle(head2->Next, &ret))
        cout << "Linked list 1 has cycle : true, and the entry point is :" << ret << endl;
    else
        cout << "Linked list 2 has cycle : false" << endl;

    return 0;
}