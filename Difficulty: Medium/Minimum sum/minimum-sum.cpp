//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    private:
    string addString(string a, string b){
        if(a.length()==0) return b;
        if(a.length()==0) return a;
    
        int carry =0;
        int sum =0;
        string ans="";
        
        int i =a.length()-1,j=b.length()-1;
        
        while(i>=0 || j>=0 || carry){
             sum = carry;
            
            if(i>=0){
                sum = sum + (a[i--] - '0');
            }
            if(j>=0){
                sum = sum + (b[j--] - '0');
            }
            
            ans.push_back((sum%10)+'0');
            carry = sum/10;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
        
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        
        string num1="",num2="";
        
        for(int i =0;i<arr.size();i++){
            
            if(i%2==0){
                if(arr[i]==0 && num1.length()==0) continue;
                
                num1 += to_string(arr[i]);
            }
            else{
                if(arr[i]==0 && num2.length()==0) continue;
                
                num2 += to_string(arr[i]);
            }
            

        }
            string ans = addString(num1,num2);
            return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends