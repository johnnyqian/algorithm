#include <stdio.h>
#include "Btree.cpp"

#include <algorithm>
using namespace std;

int count_tree(BTree *root);
int height_tree(BTree *root);
int diameter_tree(BTree *root);
bool is_balanced_tree(BTree *root);

int main()
{
    BTree *root = CreateTree();

    // count tree node
    printf("Tree Node numbers:\n");
    printf("%d", count_tree(root));
    printf("\n\n");

    // calculate the height of the tree
    printf("Tree Height:\n");
    printf("%d", height_tree(root));
    printf("\n\n");

    // calculate the diameter of the tree
    printf("Tree Diameter:\n");
    printf("%d", diameter_tree(root));
    printf("\n\n");

    // judge whether is balanced tree 
    printf("Is Balanced Tree:\n");
    printf("%d", is_balanced_tree(root));
    printf("\n");

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

// judge whether is balanced tree
bool is_balanced_tree(BTree* root)
{
    if (root)
    {
        int diff = height_tree(root->lchild) - height_tree(root->rchild);
        if (diff < -1 || diff > 1)
            return false;

        if (!is_balanced_tree(root->lchild))
            return false;

        if (!is_balanced_tree(root->rchild))
            return false;
    }

    return true;
}