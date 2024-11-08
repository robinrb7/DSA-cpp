//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long,vector<long long>,greater<long long> >minHeap;
        
        for(auto i : arr){
            minHeap.push(i);
        }
        int a = -1,b=-1;
        longd sum =0,cost =0;
        while(minHeap.size() > 1){
            sum =0;
            a = minHeap.top();
            minHeap.pop();
            b = minHeap.top();
            minHeap.pop();
            
            sum = a+b;
            cost +=sum;
            minHeap.push(sum);
        }
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends