// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    private:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return (double)(a.first)/a.second > (double)(b.first)/b.second;
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
         
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({val[i],wt[i]});
        }
        
        sort(arr.begin(),arr.end(),cmp);
        
        double res = 0.0;
        int leftCapacity = capacity;
        for(int i=0;i<n;i++){
            if(arr[i].second <= leftCapacity){
                res += arr[i].first;
                leftCapacity -= arr[i].second;
            } 
            else{
                res += ((double)arr[i].first/arr[i].second)*leftCapacity;
                break;
            }
        }
        
        return res;
    }
};
