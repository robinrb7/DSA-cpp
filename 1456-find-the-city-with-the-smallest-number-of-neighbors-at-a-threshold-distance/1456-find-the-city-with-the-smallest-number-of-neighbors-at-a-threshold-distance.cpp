class Solution {
    void dijkstra(vector<vector<pair<int,int>> > &adjList,int startNode,int dThreshold,int &minCityNo,int &minCityCounter,int n){
        vector<int> dist(n,INT_MAX);
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minHeap;
        minHeap.push({0,startNode});
        dist[startNode]=0;

        while(!minHeap.empty()){
            auto[distance , node] = minHeap.top();
            minHeap.pop();

            if(distance > dist[node]) continue;

            for(auto it : adjList[node]){
                int neigh = it.first;
                int edgeDist = it.second;

                if(distance + edgeDist < dist[neigh]){
                    dist[neigh] = distance + edgeDist;
                    minHeap.push({dist[neigh] , neigh});
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(dist[i]!= INT_MAX && dist[i]<= dThreshold) cnt++;
        }

        if(cnt < minCityCounter){
            minCityCounter = cnt;
            minCityNo = startNode;
        }
        else if(cnt==minCityCounter) minCityNo = startNode;

        return;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector< vector<pair<int,int>> >adjList(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int dist = edges[i][2];

            adjList[u].push_back({v,dist});
            adjList[v].push_back({u,dist});
        }

        int minCityNo = -1;
        int minCityCounter = INT_MAX;
        for(int i=0;i<n;i++){
            dijkstra(adjList,i,distanceThreshold,minCityNo,minCityCounter,n);
        }

        return minCityNo;
    }

};