class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>> >adjList(n);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adjList[u].push_back({v,wt});
        }

        vector<int> distance(n,INT_MAX);
        queue<pair<int,pair<int,int>> >q;
        q.push({0,{src,0}});
        distance[src]=0;

        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();
            
            if(stops > k) continue;

            for(auto it : adjList[node]){
                int neigh = it.first;
                int costNeigh = it.second;

                if(cost + costNeigh < distance[neigh] && stops <= k){
                    distance[neigh] = cost + costNeigh;
                    q.push({stops+1 , {neigh , distance[neigh]}});
                }
            }
        }

        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};