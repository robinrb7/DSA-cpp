class Solution {
private:
    void dijkstra(int n,vector<vector<pair<int,int>> > &adjList, int src, int &minCity, int &minCityReached, int distanceThreshold){

        vector<int> distance(n,INT_MAX);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        distance[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            if(distance[node] < dist) continue;

            for(auto it: adjList[node]){
                int neigh = it.first;
                int wt = it.second;

                if(dist + wt < distance[neigh]){
                    distance[neigh] = dist + wt;
                    pq.push({distance[neigh],neigh});
                }
            }

        }

        int cityReached=0;
        for(int i=0;i<n;i++){
            if(distance[i]!= INT_MAX && distance[i]<=distanceThreshold) cityReached++;
        }

        if(cityReached <= minCityReached){
            minCityReached = cityReached;
            minCity = src;
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int,int>> > adjList(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }

        int minCity = -1;
        int minCityReached = INT_MAX;

        for(int i=0;i<n;i++){
            dijkstra(n,adjList,i,minCity, minCityReached, distanceThreshold);
        }

        return minCity;
    }
};