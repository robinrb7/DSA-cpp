class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>> > adjList(n);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adjList[u].push_back({v,wt});
        }

        vector<int> price(n,INT_MAX);
        priority_queue< pair<int,pair<int,int>> , 
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{src,0}});
        price[src]=0;

        while(!pq.empty()){
            pair<int,pair<int,int>> top = pq.top();
            pq.pop();
            int stops = top.first;
            int node = top.second.first;
            int cost = top.second.second;

            if(node == dst && stops<= k+1) price[dst] = min(price[dst], cost);
            if(stops > k) continue; 

            for(auto it: adjList[node]){
                int neigh = it.first;
                int costToTravel = it.second;

                if(cost + costToTravel < price[neigh]){
                    price[neigh] =  cost + costToTravel;
                    pq.push({stops+1,{neigh,price[neigh]}});
                }
            }
        }

        return (price[dst]==INT_MAX)? -1: price[dst];
    }
};