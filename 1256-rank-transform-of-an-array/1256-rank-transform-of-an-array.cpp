class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<int> res(n,0);
    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(int i=0;i<n;i++) minHeap.push({arr[i],i});
        
        int prevMin = INT_MIN;
        int index = -1;
        int currRank = 0;
        while(!minHeap.empty()){
            pair<int,int> top = minHeap.top();
            minHeap.pop();
            index = top.second;
            
            if(top.first > prevMin){
                currRank++;
                prevMin = top.first;
            }
            
            res[index] = currRank;
        }
        
        return res;
    }
};