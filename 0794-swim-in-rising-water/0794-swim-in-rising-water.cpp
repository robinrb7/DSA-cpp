class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int  n =grid.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>> > minHeap;
        minHeap.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        int maxTime = grid[0][0];

        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};

        while(!minHeap.empty()){
            auto[nodeVal , coord] = minHeap.top();
            auto[row , col] = coord;
            minHeap.pop();

            if(nodeVal > maxTime) maxTime = nodeVal;
            if(row==n-1 && col==n-1) break;

            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && visited[nRow][nCol]==0){
                    visited[nRow][nCol]=1;
                    minHeap.push({grid[nRow][nCol],{nRow , nCol}});
                }
            }
        }

        return maxTime;
    }
};  