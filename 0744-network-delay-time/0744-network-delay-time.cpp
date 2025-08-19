class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>> >adjList(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adjList[u].push_back({v,time});
        }

        vector<int> timeConsumed(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > minHeap;
        minHeap.push({0,k});
        timeConsumed[k] = 0;

        while(!minHeap.empty()){
            auto it = minHeap.top();
            int nodeTime = it.first;
            int node = it.second;
            minHeap.pop();

            if(nodeTime > timeConsumed[node]) continue;

            for(auto temp: adjList[node]){
                int neigh = temp.first;
                int neighTime = temp.second;

                if(nodeTime + neighTime < timeConsumed[neigh]){
                    timeConsumed[neigh] = nodeTime + neighTime;
                    minHeap.push({timeConsumed[neigh] , neigh});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i=1;i<=n;i++){
            if(timeConsumed[i]==INT_MAX) return -1;
            if(timeConsumed[i] > maxi) maxi = timeConsumed[i];
        }

        return maxi;
    }
};
