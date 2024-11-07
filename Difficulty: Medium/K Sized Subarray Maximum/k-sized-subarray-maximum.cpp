//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        dq.push_front(0);
        for(int i = 1;i<k;i++){
            while(!dq.empty() && arr[i] >=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        ans.push_back(arr[dq.front()]);
        
        for(int i =k;i<arr.size();i++){
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[i] >=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(arr[dq.front()]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends