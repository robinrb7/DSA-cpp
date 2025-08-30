class Solution {
    int solve(vector<vector<int>>& grid, int row, int col1,int col2,vector<vector<vector<int>>> &dp){
        int n =grid.size(), m= grid[0].size();
        if(col1<0 || col2<0 || col1>=m || col2>=m) return INT_MIN;
        if(row==n-1){
            if(col1==col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int maxi = INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int sum=0;
                if(col1==col2){
                    sum = grid[row][col1] + solve(grid,row+1,col1+i,col2+j,dp);
                }
                else{
                    sum = grid[row][col1] + grid[row][col2] + solve(grid,row+1,col1+i,col2+j,dp);
                }
                maxi =  max(maxi,sum);
            }
        }

        return dp[row][col1][col2] = maxi;
    }

    int solveTab(vector<vector<int>>& grid){
        int n =grid.size(), m= grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0))); 

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j) dp[n-1][i][j] = grid[n-1][i];
                else dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }

        for(int row=n-2;row>=0;row--){
            for(int col1=0;col1<m;col1++){
                for(int col2=0;col2<m;col2++){

                    int maxi = INT_MIN;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            int sum=0;
                            if(col1==col2){
                                sum = grid[row][col1];
                                if(col1+i>=0 && col1+i <m && col2+j>=0 & col2+j<m)
                                    sum += dp[row+1][col1+i][col2+j];
                            }
                            else{
                                sum = grid[row][col1] + grid[row][col2];
                                if(col1+i>=0 && col1+i <m && col2+j>=0 & col2+j<m)
                                    sum += dp[row+1][col1+i][col2+j];
                            }
                            maxi =  max(maxi,sum);
                        }
                    }                    
                    dp[row][col1][col2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
public:
    int cherryPickup(vector<vector<int>>& grid){
        int n =grid.size(), m= grid[0].size();

        return solveTab(grid);
    }
};