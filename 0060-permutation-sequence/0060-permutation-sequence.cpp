class Solution {
    private:
    void solve(int n, int k,string &ans){
        int fact =1;
        vector<int> numbers;
        for(int i =1;i<n;i++){
            fact = fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k=k-1;
        while(true){
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size()==0) return;

            k = k%fact;
            fact = fact/numbers.size();
        }

    }
public:
    string getPermutation(int n, int k) {
        string ans ="";
        solve(n,k,ans);
        return ans;
    }
};