#include <string>
#include <iostream>
using namespace std;

string postOrder(string preOrder, string inOrder);

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    #endif

    string preOrder, inOrder;
    cin >> preOrder;
    cin >> inOrder;

    cout << postOrder(preOrder, inOrder) << endl;
    return 0;
}

string postOrder(string preOrder, string inOrder)
{
    if (preOrder.length() > 1)
    {
        char root = preOrder[0];
        int root_index = inOrder.find(root);

        string preOrderL = preOrder.substr(1, root_index);
        string preOrderR = preOrder.substr(root_index + 1);

        string inOrderL = inOrder.substr(0, root_index);
        string inOrderR = inOrder.substr(root_index + 1);

        return postOrder(preOrderL, inOrderL) + postOrder(preOrderR, inOrderR) + root;
    }
    else
    {
        return preOrder;
    }
}