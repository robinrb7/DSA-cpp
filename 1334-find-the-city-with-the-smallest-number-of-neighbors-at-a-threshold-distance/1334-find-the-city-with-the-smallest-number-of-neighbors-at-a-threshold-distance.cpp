class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            distance[u][v] = wt;
            distance[v][u] = wt;
        }

        for(int i=0;i<n;i++) distance[i][i]=0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][k]==INT_MAX || distance[k][j]==INT_MAX) continue;

                    int costToReach = distance[i][k] + distance[k][j];
                    distance[i][j] = min(distance[i][j], costToReach);
                }
            }
        }

        int minCityReached = INT_MAX;
        int minCity = -1;

        for(int i=0;i<n;i++){
            int cityReachedCnt=0;
            for(int j=0;j<n;j++){
                if(distance[i][j]!=INT_MAX && distance[i][j] <= distanceThreshold) cityReachedCnt++;
            }
            if(cityReachedCnt <= minCityReached){
                minCityReached = cityReachedCnt;
                minCity = i;
            } 
        }

        return minCity;
    }
};