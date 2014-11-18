#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* Next;
}SLNode;

SLNode* createCircularLinkedList(int n);
int recursive(int n, int m);
int deduction(int n, int m);

int main()
{
    freopen("Input.txt", "r", stdin);
    int n, k, m; // 1<=k<=n, m>=1
    cin >> n >> k >> m;

    // 1. use circular linked list
    SLNode *head, *curr, *tmp;
    head = createCircularLinkedList(n); // create a circular singly linked list
    curr = head;

    // move to the (k-1)-th person, if k=1, then curr should point to header
    for (int i = 1; i < k; i++)
    {
        curr = curr->Next;
    }

    cout << "The sequence of people out of the list:" << endl;
    while (curr != curr->Next)
    {
        for (int i = 1; i < m;i++)
        {
            curr = curr->Next;
        }
        tmp = curr->Next;
        curr->Next = tmp->Next;

        cout << tmp->data << endl;
        free(tmp);
    }
    cout << curr->data << endl;

    // 2. use recursion formula
    cout << "The number of people who lastly out of the list: " << (recursive(n, m) + k - 1) % n + 1 << endl;

    // 3. use reverse deduction
    cout << "The number of people who lastly out of the list: " << (deduction(n, m) + k - 1) % n + 1 << endl;
}

SLNode* createCircularLinkedList(int n)
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
    p->Next = head->Next;

    return head;
}

// recursion formula
// f(1)=0;
// f(n)=(f(n-1)+m)%n;
int recursive(int n, int m)
{
    if (n > 1)
        return (recursive(n - 1, m) + m) % n;
    return 0;
}

// reverse deduction
int deduction(int n, int m)
{
    int pos = 0;
    for (int i = 2; i <= n; i++)
        pos = (pos + m) % i;
    return pos;
}