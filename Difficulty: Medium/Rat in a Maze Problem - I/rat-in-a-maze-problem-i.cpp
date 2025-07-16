class Solution {
    private:
     void solve(vector<vector<int> > &grid,vector<string> &ans,string temp, int row, int col,int nRow, int nCol){
        if(row<0 || row==nRow || col<0 || col==nCol || grid[row][col]==0){
            return;
        }
        
        if(row==nRow-1 && col==nCol-1){
            ans.push_back(temp);
            return;
        }
        

        grid[row][col]=0;

        //MOVE UP
        solve(grid,ans,temp+'U',row-1,col,nRow,nCol);

        //MOVE DOWN
        solve(grid,ans,temp+'D',row+1,col,nRow,nCol);

        //MOVE LEFT
        solve(grid,ans,temp+'L',row,col-1,nRow,nCol);

        //MOVE RIGHT
        solve(grid,ans,temp+'R',row,col+1,nRow,nCol);

        grid[row][col]=1;
        
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;

        int nRow = maze.size();
        int nCol = maze[0].size();
        string temp;

        solve(maze,ans,temp,0,0,nRow,nCol);
        sort(ans.begin(),ans.end());
        return ans;
    }
};