//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
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
  public:
  
  void mapping(map<int,int> &nodeToIndx,int in[],int n){
      for(int i=0;i<n;i++){
          nodeToIndx[in[i]]=i;
      }
  }
  
  Node* solve(int in[],int post[],int &index, int startIndx,int endIndx,int n,map<int,int> &nodeToIndx){
      if(index < 0 || startIndx > endIndx){
          return NULL;
      }
      int element = post[index--];
      Node* root = new Node(element);
      int pos = nodeToIndx[element];
      
      root->right = solve(in,post,index,pos+1,endIndx,n,nodeToIndx);
      root->left = solve(in,post,index,startIndx,pos-1,n,nodeToIndx);
      return root;
  }
    Node *buildTree(int n, int in[], int post[]) {
        if(n==0){
            return NULL;
        }
        
        map<int,int> nodeToIndx;
        mapping(nodeToIndx,in,n);
        int index = n-1;
        int startIndx =0, endIndx =n-1;
        
        Node* ans = solve(in,post,index,startIndx,endIndx,n,nodeToIndx);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends