//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    private:
    void countNodes(Node* root, int &count){
        if(root==NULL) return;
        
        countNodes(root->left, count);
        count++;
        countNodes(root->right,count);
    }
    
    void solve(Node* root, int k, int &i, int&ans){
        if(root==NULL) return;
        
        solve(root->left,k,i,ans);
        
        i++;
        if(i==k){
            ans = root->data;
            return;
        }
        
        solve(root->right,k,i,ans);
    }
  public:
    int kthLargest(Node *root, int k) {
        if(root==NULL) return -1;
        
        int n =0;
        countNodes(root,n);
        
        int i=0;
        int ans=-1;
        solve(root,n-k+1,i,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Solution ob;
        cout << ob.kthLargest(head, k) << endl;

        cout << "~"
             << "\n";
    }
    return 1;
}
// } Driver Code Ends