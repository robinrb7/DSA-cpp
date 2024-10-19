//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
     private:
    
    Node* solve(vector<int> inorder, vector<int> postorder,int n,int &postIndex, int inStartIndex,int inEndIndex,map<int,int>&findIndex){
        if(postIndex<0 || inStartIndex>inEndIndex){
            return NULL;
        }
        
        int element = postorder[postIndex--];
        int index = findIndex[element];
        
        if(index==-1){
            return NULL;
        }
        
        Node* root = new Node(element);
        
        root->right = solve(inorder,postorder,n,postIndex,index+1,inEndIndex,findIndex);
        root->left = solve(inorder,postorder,n,postIndex,inStartIndex,index-1,findIndex);
        
        return root;
    }
    
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
    int n = inorder.size();
       if(n<=0){
            return NULL;
        }
        
        map<int,int> findIndex;
        for(int i =0;i<n;i++){
            findIndex[inorder[i]] =i;
        }
        
        int postIndex=n-1;
        int inStartIndex =0;
        int inEndIndex = n-1;
        
        return solve(inorder,postorder,n,postIndex,inStartIndex,inEndIndex,findIndex);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends