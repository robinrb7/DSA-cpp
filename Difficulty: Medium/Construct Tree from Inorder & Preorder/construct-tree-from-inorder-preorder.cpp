//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void mapping(map<int,int> &nodeToIndx,int in[],int n){
        for(int i =0;i<n;i++){
            nodeToIndx[in[i]] = i;
        }
    }
    
    Node* solve(int in[],int inStartIndx, int inEndIndx, 
               int pre[],int &index,
               map<int,int> &nodeToIndx, int n)
    {
        if(index>=n|| inStartIndx>inEndIndx){
            return NULL;
        } 
        
        int element = pre[index++];
        Node* root = new Node(element);
        int pos = nodeToIndx[element];
        
        root->left = solve(in,inStartIndx,pos-1,pre,index,nodeToIndx,n);
        root->right = solve(in,pos+1,inEndIndx,pre,index,nodeToIndx,n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
      if(n==0){
          return NULL;
      }
       map<int,int> nodeToIndx;
       mapping(nodeToIndx,in,n);
       
       int inStartIndx=0, inEndIndex=n-1;
       int index =0;
       
        Node* ans = solve(in,inStartIndx,inEndIndex,pre,index,nodeToIndx,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends