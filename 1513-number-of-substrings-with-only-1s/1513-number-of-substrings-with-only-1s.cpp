class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        const long long MOD = 1000000007; 
        long long cnt=0, ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans = (ans + ( ((cnt*(cnt+1))/2) % MOD) ) % MOD;
                cnt=0;
            }
            else cnt++;
        }

        ans = (ans + ( ((cnt*(cnt+1))/2) % MOD) ) % MOD;
        return (int)(ans % MOD);
    }
};