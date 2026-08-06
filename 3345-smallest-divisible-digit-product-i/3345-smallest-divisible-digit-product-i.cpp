class Solution {
public:
    int smallestNumber(int n, int t) {
        int digit1=-1, digit2=-1;

        while(1){
            int num=n;

            digit1 = num%10;
            if(num>=10) digit2 = num/10;

            int product = digit1*digit2;
            if(product%t==0) return n;

            n++;
        }
    }
};