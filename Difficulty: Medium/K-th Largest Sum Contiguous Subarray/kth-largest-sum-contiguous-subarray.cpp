//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        vector<int> vec;
        
        for(int i =0;i<arr.size();i++){
            int sum =0;
            for(int j =i;j<arr.size();j++){
                sum = sum + arr[j];
                vec.push_back(sum);
            }
        }
        
        sort(vec.begin(),vec.end());
        
        return vec[vec.size()-k];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends