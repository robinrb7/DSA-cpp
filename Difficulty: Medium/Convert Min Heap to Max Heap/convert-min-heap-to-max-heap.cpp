//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void heapify(vector<int> &arr, int &index, int n){
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        
        if(left<n && arr[largest] < arr[left]) largest = left;
        if(right<n && arr[largest] < arr[right]) largest = right;
        
        if(largest != index){
            swap(arr[largest],arr[index]);
            heapify(arr,largest,n);
        }
        
    }
    void buildHeap(vector<int> &arr, int n){
        
        for(int i  = n/2 -1;i>=0;i--){
            heapify(arr,i,n);
        }
    }
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        if(N<=0) return;
        
        buildHeap(arr,N);
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends