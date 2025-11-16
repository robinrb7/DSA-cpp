class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int> >visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                visited[0][j]=1;
            }

            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                visited[n-1][j]=1;
            }
        }
        for(int i=1;i<n-1;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=1;
            }

            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                visited[i][m-1]=1;
            }   
        }

        int dRow[4] = {0,0,-1,1};
        int dCol[4] = {-1,1,0,0};

        while(!q.empty()){
            auto[row,col]=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m
                    && !visited[nRow][nCol] && board[nRow][nCol]=='O'){
                        visited[nRow][nCol] = 1;
                        q.push({nRow,nCol});
                    }
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O') board[i][j]='X';
            }
        }

        return;
    }
};