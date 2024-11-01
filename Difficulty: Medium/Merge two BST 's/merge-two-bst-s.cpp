//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
private:
    void bstToList(Node* root, Node* &head, Node* &tail) {
        if (root == NULL) return;

        // Convert the left subtree
        bstToList(root->left, head, tail);

        // Process current node
        if (head == NULL) {
            head = root;
            tail = root;
        } else {
            tail->right = root;
            root->left = tail;
            tail = root;
        }

        // Convert the right subtree
        bstToList(root->right, head, tail);
    }
    
    Node* sortList(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;

        Node* tempHead = nullptr;
        Node* tempTail = nullptr;

        // Initialize tempHead and tempTail
        if (head1->data < head2->data) {
            tempHead = tempTail = head1;
            head1 = head1->right;
        } else {
            tempHead = tempTail = head2;
            head2 = head2->right;
        }

        // Merge the two sorted DLLs
        while (head1 && head2) {
            if (head1->data < head2->data) {
                tempTail->right = head1;
                head1->left = tempTail;
                tempTail = head1;
                head1 = head1->right;
            } else {
                tempTail->right = head2;
                head2->left = tempTail;
                tempTail = head2;
                head2 = head2->right;
            }
        }

        // Attach remaining nodes from head1 or head2
        tempTail->right = (head1) ? head1 : head2;
        if (tempTail->right) tempTail->right->left = tempTail;

        return tempHead;
    }
    
    int countNodes(Node* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->right;
        }
        return count;
    }
    
    Node* listToBst(Node* &head, int n) {
        if (n <= 0) return NULL;

        // Recursively construct the left subtree
        Node* left = listToBst(head, n / 2);

        // Create root node with the current head
        Node* root = head;
        root->left = left;

        // Move head to the next node
        head = head->right;

        // Recursively construct the right subtree
        root->right = listToBst(head, n - n / 2 - 1);

        return root;
    }
    
    void inorder(Node* root, vector<int> &vec) {
        if (root == NULL) return;

        inorder(root->left, vec);
        vec.push_back(root->data);
        inorder(root->right, vec);
    }

public:
    vector<int> merge(Node *root1, Node *root2) {
        // Convert both BSTs to sorted doubly linked lists
        Node* head1 = NULL;
        Node* tail1 = NULL;
        Node* head2 = NULL;
        Node* tail2 = NULL;

        bstToList(root1, head1, tail1);
        bstToList(root2, head2, tail2);

        // Merge the two sorted DLLs
        Node* mergedHead = sortList(head1, head2);

        // Convert merged DLL back to a balanced BST
        int nodeCount = countNodes(mergedHead);
        Node* balancedRoot = listToBst(mergedHead, nodeCount);

        // Get inorder traversal of the balanced BST
        vector<int> result;
        inorder(balancedRoot, result);
        return result;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends