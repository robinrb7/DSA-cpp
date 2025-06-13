class Solution {
    private:
    void solve(vector<vector<int>>& maze, vector<string> &ans, string &temp,int n, int row, int col,vector<vector<int>> &visited){
        if(row==n-1 && col == n-1){
            ans.push_back(temp);
            return;
        }
        
        visited[row][col] =1;
        
        if( row+1 <n && col<n && maze[row+1][col]==1 && visited[row+1][col] !=1){
            temp += 'D';
            solve(maze,ans,temp,n,row+1,col,visited);
            temp.pop_back();
        }
        
        if ( row <n && col-1>=0 && maze[row][col-1]==1 && visited[row][col-1] !=1){
            temp += 'L';
            solve(maze,ans,temp,n,row,col-1,visited);
            temp.pop_back();
        }
        
        if(row <n && col+1<n && maze[row][col+1]==1 && visited[row][col+1] !=1){
            temp += 'R';
            solve(maze,ans,temp,n,row,col+1,visited);
            temp.pop_back();
        }
        
        if(row-1 >=0 && col<n && maze[row-1][col]==1 && visited[row-1][col] !=1){
            temp += 'U';
            solve(maze,ans,temp,n,row-1,col,visited);
            temp.pop_back();
        }
        
        visited[row][col] =0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string>ans;
        if(maze[0][0]==0) return ans;
        
        int n = maze.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        string temp = "";
        int row =0;
        int col =0;
        
        solve(maze,ans,temp,n,row,col,visited);
        
        return ans;
        
    }
};