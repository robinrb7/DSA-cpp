//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
    private:
    int findIndex(string str,int s, int e){
        if(s>e){
            return -1;
        }
        
      
        stack<char>st;
        
        for(int i =s; i<=e;i++){
            if(str[i]=='('){
                st.push(str[i]);
            }
            else if(str[i]==')'){
                if(st.top()=='('){
                    st.pop();
                
                if(st.empty()){
                    return i;
                }
                }
            }
        }
        return -1;
    }
    Node* solve(string str,int s,int e){
        if(s>e){
            return NULL;
        }
        
        int num=0;
        while(s<=e && (str[s]>='0' && str[s]<='9')){
            num = num*10 ;
            num = num + (str[s] -'0') ;
            s++;
        }
        
        
        Node * root = new Node(num);
        
        int index=-1;
        if(str[s]=='(' && s<e){
            index = findIndex(str,s,e);
        }
        
        
        if(index != -1){
            root->left = solve(str,s+1,index-1);
            root->right = solve(str,index+2,e-1);
        }
        
        return root;
    }
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        if(str==""){
            return NULL;
        }
        
        int s =0, e = str.size()-1;
        
        Node* root = solve(str,s,e);
        
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends