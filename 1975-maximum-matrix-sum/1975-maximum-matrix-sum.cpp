class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        long long sum = 0;
        int negCnt = 0;
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                mini = min(mini,abs(matrix[i][j]));

                if(matrix[i][j]<0) negCnt++;
            }
        }

        if(negCnt & 1) return (sum - 2*mini);
        return sum;
    }
};