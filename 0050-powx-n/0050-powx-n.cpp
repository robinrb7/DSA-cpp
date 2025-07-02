class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0.0;
        if(n==0) return 1.0;

        double ans = 1.0;
        long long N = n;
        if(n<0){
            x = 1.0/x;
            N = N*-1;
        }

        bool flag =0;
        if(x<0){
            x= x*-1.0;
            if(N%2!=0) flag=1;
        }

        while(N>1){
            if(N%2!=0){
                ans = ans*x;
                N= N-1;
            }
            else{
                x = x*x;
                N = N/2;
            }
        }

        ans = ans*x;
        if(flag) ans = ans*-1.0;
        return ans;
    }
};