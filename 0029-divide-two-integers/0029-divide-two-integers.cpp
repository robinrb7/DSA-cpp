class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        bool sign = 0;
        if(dividend<0 && divisor>=0) sign =1;
        else if(dividend>=0 && divisor<0) sign = 1;

        long  dividend_new = abs((long)dividend);
        long  divisor_new =abs((long)divisor);

        long  quotient = 0;
        while(dividend_new >=divisor_new){
            int cnt = 0;
            while(cnt<31 && dividend_new >= divisor_new<<(cnt+1)) cnt++;

            quotient += 1<<cnt;
            dividend_new = dividend_new - (divisor_new<<cnt);

        }

       
        if(quotient == (1<<31) && !sign) return INT_MAX;
        if(quotient == (1<<31) && sign) return INT_MIN;

         if(sign) quotient=-quotient;
        return quotient;

    }
};