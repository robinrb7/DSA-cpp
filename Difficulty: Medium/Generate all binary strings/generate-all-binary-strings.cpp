// User function Template for C++

class Solution {
    void solve(int n, int index, string temp,vector<string> &res){
        if(index==n){
            res.push_back(temp);
            return;
        } 
        
        temp.push_back('0');
        solve(n,index+1,temp ,res);
        temp.pop_back();
        
        if(temp.empty() || temp.back() !='1'){
            temp.push_back('1');
            solve(n,index+1,temp,res);
            temp.pop_back();
        }
        
    }
  public:
    vector<string> generateBinaryStrings(int num) {
        vector<string> res;
        if(num==0) return res;
        
        string temp="";
        solve(num,0,temp,res);
        return res;
        
    }
};