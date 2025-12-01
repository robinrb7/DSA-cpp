class Solution {
    const int MOD = int(1e9 +7);
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>> > adjList(n);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adjList[u].push_back({v,time});
            adjList[v].push_back({u,time});
        }

        vector<long long> timeTaken(n,LLONG_MAX);
        vector<int> numWays(n,0);
        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > minHeap;
        minHeap.push({0,0});
        timeTaken[0]=0;
        numWays[0]=1;

        while(!minHeap.empty()){
            auto [time , node] = minHeap.top();
            minHeap.pop();

            if(time > timeTaken[node]) continue;
            for(auto it : adjList[node]){
                int neigh = it.first;
                int neighTime = it.second;

                if(time + neighTime == timeTaken[neigh]) numWays[neigh] = (numWays[neigh] + numWays[node])%MOD;
                else if(time + neighTime < timeTaken[neigh]){
                    timeTaken[neigh] = time + neighTime;
                    minHeap.push({timeTaken[neigh] , neigh});
                    numWays[neigh] = numWays[node]; 
                }

            }
        }

        return numWays[n-1]% MOD;
    }
};