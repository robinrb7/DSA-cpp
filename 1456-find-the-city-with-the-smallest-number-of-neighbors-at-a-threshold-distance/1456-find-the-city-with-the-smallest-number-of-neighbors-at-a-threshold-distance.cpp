class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> distMatrix(n,vector<int>(n,INT_MAX));

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int dist = edges[i][2];

            distMatrix[u][v] = dist;
            distMatrix[v][u] = dist;
        }

        for(int i=0;i<n;i++){
            distMatrix[i][i]=0;
        }

        for(int k=0;k <n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distMatrix[i][k] != INT_MAX && distMatrix[k][j] != INT_MAX)
                        distMatrix[i][j] = min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
                }
            }
        }

        int mini = INT_MAX;
        int minCity = -1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(distMatrix[i][j] != INT_MAX && distMatrix[i][j] <=distanceThreshold) cnt++;
            }
            if(cnt < mini){
                mini = cnt;
                minCity = i;
            } 
            else if(mini == cnt) minCity = i;
        }
        return minCity;
    }

};