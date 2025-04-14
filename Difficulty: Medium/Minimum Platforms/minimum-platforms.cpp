//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    static bool cmp(pair<int,bool>&a, pair<int,bool>&b){
        if(a.first==b.first) return a.second < b.second;
        return a.first < b.first;
    }
  public:
    
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        vector<pair<int,bool>>temp;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            temp.push_back({arr[i],0});
            temp.push_back({dep[i],1});
        }
        
        sort(temp.begin(),temp.end(),cmp);
        int depart = temp[0].second;
        int count=0;
        int maxi = 0;
        
        for(int i =0;i<temp.size();i++){
            if(!temp[i].second) count++;
            else count--;
            maxi = max(maxi,count);
        }
        
        return maxi;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends