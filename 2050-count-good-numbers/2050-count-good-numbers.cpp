class Solution {
    const int MOD = 1e9 +7;
    private:
    long long power(long long x, long long n){
        long long ans = 1;
        if(n==0) return ans;
        
        while(n>0){
            if(n%2!=0){
                ans = (ans*x) % MOD;
                n= n-1;
            }
            else {
                x = (x*x) %MOD;
                n=n/2;
            }
        }

        return ans%MOD;
    }
public:
    int countGoodNumbers(long long n) {
        if(n==0) return 0;
        
        long long evenPower = (n+1)/2;
        long long oddPower = n/2;

        return (power(5,evenPower) * power(4,oddPower))%MOD;
    }
};