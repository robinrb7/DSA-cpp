//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        
        unordered_map<int,stack<int> > umap;
        
        for(int i =0;i<2*e;i=i+2){
            
            umap[A[i]].push(A[i+1]);
        }
        
        for(int i =0;i<2*e;i=i+2){
            
            if(umap[B[i]].top() != B[i+1]){
                return false;
            }
            
            umap[B[i]].pop();
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends