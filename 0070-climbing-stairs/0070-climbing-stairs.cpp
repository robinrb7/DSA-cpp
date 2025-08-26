class Solution {
    private:
    int solve(int n){
        int prev1 = 1;
        int prev2 = 1;
        int curr =-1;
        
        for(int index=2;index<=n;index++){
            curr = prev1 + prev2;

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int climbStairs(int n) {
        
        return solve(n);
    }
};