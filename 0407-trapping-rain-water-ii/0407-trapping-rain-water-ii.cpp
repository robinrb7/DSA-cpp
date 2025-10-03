class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if(n<3 || m<3) return 0;

        vector<vector<bool>> visited(n,vector<bool>(m,0));
        priority_queue< pair<int,pair<int,int>> ,
                        vector< pair<int,pair<int,int>>>,
                        greater< pair<int,pair<int,int>>> > minHeap;

        for(int i=0;i<n;i++){
            minHeap.push({heightMap[i][0], {i,0}});
            visited[i][0]=true;
            minHeap.push({heightMap[i][m-1], {i,m-1}});
            visited[i][m-1]=true;
        } 
        for(int j=1;j<m-1;j++){
            minHeap.push({heightMap[0][j], {0,j}});
            visited[0][j]=true;
            minHeap.push({heightMap[n-1][j], {n-1,j}});
            visited[n-1][j]=true;
        } 

        int totalWater=0, level = 0;
        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1}; 

        while(!minHeap.empty()){
            auto[height, cord] = minHeap.top();
            auto[row,col] = cord;
            minHeap.pop();

            level = max(level,height);

            for(int i =0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && visited[nRow][nCol]!=true){
                    visited[nRow][nCol] = true;
                    minHeap.push({heightMap[nRow][nCol], {nRow,nCol}});
                    if(heightMap[nRow][nCol]<level) 
                        totalWater += level - heightMap[nRow][nCol];
                }
            }

        }

        return totalWater;
    }
};