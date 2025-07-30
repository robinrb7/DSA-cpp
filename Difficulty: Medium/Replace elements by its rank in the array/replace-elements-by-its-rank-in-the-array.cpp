// User function Template for C++
class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int>res;
        
        set<int> oSet;
        for(int i=0;i<N;i++) oSet.insert(arr[i]);
        
        unordered_map<int,int> uMap;
        int currRank=1;
        for(auto it:oSet){
            uMap[it] = currRank++;
        }
        
        for(int i=0;i<N;i++){
            res.push_back(uMap[arr[i]]);
        }
        
        return res;
    }
};
