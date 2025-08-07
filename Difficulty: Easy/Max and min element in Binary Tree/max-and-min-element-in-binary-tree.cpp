/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        if(!root) return 0;
        while(root->right) root=root->right;
        return root->data;
    }

    int findMin(Node *root) {
        if(!root) return 0;
        while(root->left) root=root->left;
        return root->data;
    }
};