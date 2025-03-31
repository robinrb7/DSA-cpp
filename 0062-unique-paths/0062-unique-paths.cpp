class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = min(m-1,n-1);
        long long ans = 1;

        for(int i =0;i<r;i++){
            ans = ans* (N-i)/(i+1);
        }

        return (int)ans;
    }
};