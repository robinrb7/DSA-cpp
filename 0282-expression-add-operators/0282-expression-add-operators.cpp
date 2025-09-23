class Solution {
    void solve(string &num, int target,string temp, vector<string> &res,int index,long long resultant,long long prev){
        int n =num.size();
        if(index==n){
            if(resultant==target) res.push_back(temp);
            return;
        }

        for(int i=index;i<n;i++){
            if(i>index && num[index]=='0') return;
            string str = num.substr(index,i-index+1);
            long long curr_val = stoll(str);
            

            if(index==0){
                solve(num,target,temp+str,res,i+1,curr_val,curr_val);
            }
            else{
                solve(num,target,temp+ '+' +str,res,i+1,resultant + curr_val,curr_val);
                solve(num,target,temp+ '-' +str,res,i+1,resultant - curr_val,-curr_val);
                solve(num,target,temp+ '*' +str,res,i+1,(prev*curr_val) + (resultant-prev),prev*curr_val);
            }
        }
        
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string temp="";
        solve(num,target,temp,res,0,0,0);
        return res;
    }
};