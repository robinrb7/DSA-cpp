class Solution {
    private:
    void solve(string num, int target, string temp, vector<string>&ans, int index,int n,long long prev,long long resultant){
        if(index==n){
            if(resultant==target){
                ans.push_back(temp);
            }
            return;
        }

        for(int i= index;i<n;i++){
            string str = num.substr(index,i-index+1);
            long long number = stoll(str);
            if(i>index && num[index]=='0') break;

            if(index==0){
                solve(num,target,temp+str,ans,i+1,n,number,number);
            }
            else{
                solve(num,target,temp + '+' + str,ans,i+1,n,number,resultant+number);
                solve(num,target,temp + '-' + str,ans,i+1,n,-number,resultant-number);
                solve(num,target,temp + '*' + str,ans,i+1,n,prev*number,(resultant - prev)+(prev*number));
            }
        }

    }
public:
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        vector<string> ans;
        string temp="";

        solve(num,target,temp,ans,0,n,0,0);
        return ans;
    }
};