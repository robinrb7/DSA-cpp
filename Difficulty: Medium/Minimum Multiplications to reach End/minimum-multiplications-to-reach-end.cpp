// User function Template for C++

class Solution {
    const int MOD = 1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        
        vector<int> stepsTaken(1e5,INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,start});
        stepsTaken[start]=0;
        
        while(!q.empty()){
            auto [steps , node] = q.front();
            q.pop();
            
            for(auto it: arr){
                int num = (it* node)% MOD;
                
                if(num == end) return steps+1;
                if(steps+1 < stepsTaken[num]){
                    stepsTaken[num] = steps+1;
                    q.push({steps+1 , num});
                }
            }
        }
        
        return -1;
        
    }
};
