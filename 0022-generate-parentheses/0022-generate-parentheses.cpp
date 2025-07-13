class Solution {
    void solve(int n, string temp,int numOpen, int numClose, vector<string>&res){
        if(numOpen > n || numClose>numOpen ) return;
        if(numOpen == n && numClose==n){
            res.push_back(temp);
            return;
        }

        temp.push_back('(');
        solve(n,temp,numOpen+1,numClose,res);
        temp.pop_back();

        temp.push_back(')');
        solve(n,temp,numOpen,numClose+1,res);
        temp.pop_back();

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        if(n==0) return res;

        string temp="";
        solve(n,temp,0,0,res);

        return res;
    }
};