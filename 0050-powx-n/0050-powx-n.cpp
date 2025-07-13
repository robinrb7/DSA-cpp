class Solution {
    private:
    void solve(double x ,long long n,double &ans){
        if(n<=0) return;

        if(n%2!=0){
            ans = ans*x;
            n=n-1;
        }
        else{
            x=x*x;
            n=n/2;
        }

        return solve(x,n,ans);
    }
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(x==0) return 0.0;

        bool reciprocal = 0;
        long long N = n;
        if(n<0){
            reciprocal = 1;
            N=-N;
        }
        double ans = 1.0;
        solve(x,N,ans);

        if(reciprocal) ans = 1/ans;
        return ans;
    }
};