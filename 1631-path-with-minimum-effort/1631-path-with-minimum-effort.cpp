class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue< pair<int,pair<int,int>> ,
                        vector<pair<int,pair<int,int>>>, 
                        greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> minEffort(n,vector<int>(m,INT_MAX));

        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};

        pq.push({0,{0,0}});
        minEffort[0][0]=0;

        while(!pq.empty()){
            auto [effort , cord] = pq.top();
            pq.pop();
            auto [row, col] = cord;

            if(row==n-1 && col==m-1) return effort;

            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                    int newEffort = max(effort,abs(heights[row][col] - heights[nRow][nCol]));

                    if(minEffort[nRow][nCol]==INT_MAX){
                        minEffort[nRow][nCol] = newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                        
                    else if(newEffort < minEffort[nRow][nCol]){
                        minEffort[nRow][nCol] = newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                }
            }
        }

        return -1;
    }
};