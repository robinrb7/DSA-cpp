class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0) ,curr(m,0);

        int cnt = 0;
        for(int j=0;j<m;j++){
            prev[j] = matrix[0][j];
            cnt += prev[j];
        } 

        for(int i=1;i<n;i++){
            curr[0] = matrix[i][0];
            cnt += curr[0];
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) curr[j]=0;
                else{
                    int up = prev[j];
                    int left = curr[j-1];
                    int diagonal = prev[j-1];

                    curr[j] = 1 + min(up,min(left,diagonal));
                }
                cnt += curr[j];
            }
            prev = curr;
        }
        return cnt;
    }
};