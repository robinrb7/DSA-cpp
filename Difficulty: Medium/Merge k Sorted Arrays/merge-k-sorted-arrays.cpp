//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    
    class Node{
      public:
      int data;
      int row;
      int col;
      
      Node(int data,int row,int col){
          this->data = data;
          this->row = row;
          this->col = col;
      }
    };
    class compare{
        public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<Node*,vector<Node*>,compare> minHeap;
        
        for(int i =0;i<K;i++){
            Node* temp = new Node(arr[i][0],i,0);
            minHeap.push(temp);
        }
        
        while(!minHeap.empty()){
            Node* top = minHeap.top();
            minHeap.pop();
            
            ans.push_back(top->data);
            
            int i = top->row;
            int j = top->col;
            if(j+1 < arr[i].size()){
                Node* next = new Node(arr[i][j+1],i,j+1);
                minHeap.push(next);
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends