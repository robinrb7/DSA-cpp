//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
   
  public:

    string longestCommonPrefix(vector<string> arr) {
       string ans="";
       int n= arr.size();
       if(n<=0) return ans;
       
       for(int i =0;i<arr[0].length();i++){
           char ch = arr[0][i];
           bool match = true;
           
           for(int j =1;j<n;j++){
               if(ch!= arr[j][i] || arr[j].size() < i){
                   match = false;
                   break;
               }
           }
           
           if(match) ans.push_back(ch);
           else break;
       }
       
       if(ans.size()<=0) ans="-1";
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends