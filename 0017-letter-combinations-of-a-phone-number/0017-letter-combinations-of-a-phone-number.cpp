class Solution {
    private:
    void createMap(unordered_map<char,string> &hashMap){
        hashMap['2']="abc";
        hashMap['3']="def";
        hashMap['4']="ghi";
        hashMap['5']="jkl";
        hashMap['6']="mno";
        hashMap['7']="pqrs";
        hashMap['8']="tuv";
        hashMap['9']="wxyz";
    }

    void solve(string &digits,string temp, int index, vector<string>&res, int n,unordered_map<char,string> &hashMap){
        if(index==n){
            res.push_back(temp);
            return;
        }

        for(int i =0;i<hashMap[digits[index]].length();i++){
            temp += hashMap[digits[index]][i];

            solve(digits,temp,index+1,res,n,hashMap);
            temp.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.length();
        if(n==0) return res;

        unordered_map<char,string> hashMap;
        createMap(hashMap);

        string temp="";
        solve(digits,temp,0,res,n,hashMap);
        return res;
    }
};