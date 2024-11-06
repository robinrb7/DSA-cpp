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
        
        Node(int data, int row,int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };
    
    class compare{
        public:
        
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };
    
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        priority_queue<Node*,vector<Node*>,compare> pq;
        
        for(int i =0;i<K;i++){
            Node* temp = new Node(arr[i][0],i,0);
            pq.push(temp);
        }
        
        while(!pq.empty()){
            Node* temp = pq.top();
            ans.push_back(temp->data);
            pq.pop();
            
            int i = temp->row;
            int j = temp->col;
            if(j+1 <arr[i].size()){
                Node* next = new Node(arr[i][j+1],i,j+1);
                pq.push(next);
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