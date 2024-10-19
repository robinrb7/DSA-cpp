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
    private:
    
    int findIndex(int in[],int num,int n){
        for(int i =0;i<n;i++){
            if(in[i]==num){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int n,int &preIndex, int inStartIndex,int inEndIndex){
        if(preIndex>=n || inStartIndex>inEndIndex){
            return NULL;
        }
        
        int element = pre[preIndex++];
        int index = findIndex(in,element,n);
        
        if(index==-1){
            return NULL;
        }
        
        Node* root = new Node(element);
        
        root->left = solve(in,pre,n,preIndex,inStartIndex,index-1);
        root->right = solve(in,pre,n,preIndex,index+1,inEndIndex);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        if(n<=0){
            return NULL;
        }
        
        int preIndex=0;
        int inStartIndex =0;
        int inEndIndex = n-1;
        
        return solve(in,pre,n,preIndex,inStartIndex,inEndIndex);
        
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