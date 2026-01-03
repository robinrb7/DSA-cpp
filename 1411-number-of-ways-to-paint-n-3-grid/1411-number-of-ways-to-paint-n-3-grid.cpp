class Solution {
public:
    int numOfWays(int n) {
        if(n==0) return 0;
        
        const int MOD= 1e9 + 7;
        long twoPattern = 6, threePattern = 6;
        n--;

        while(n>0){
            long newTwoPattern = (3*twoPattern + 2*threePattern) % MOD;
            threePattern = (2*twoPattern + 2*threePattern) % MOD;
            twoPattern = newTwoPattern;

            n--;
        }

        return (twoPattern + threePattern) % MOD;
    }
};