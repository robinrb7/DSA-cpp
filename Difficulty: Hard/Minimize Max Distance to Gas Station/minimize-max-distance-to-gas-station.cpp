class Solution {
    private:
    int func(vector<int>&stations, long double dist){
        int n = stations.size();
        int cnt = 0;
        for(int i = 0;i<n-1;i++){
            int stPlaced = (stations[i+1]-stations[i])/dist;
            if((stations[i+1]-stations[i])/dist== stPlaced * dist) stPlaced--;
            
            cnt += stPlaced;
        }
        return cnt;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n= stations.size();
        
        long double maxi = 0;
        for(int i =0;i<n-1;i++){
            long double diff = stations[i+1] - stations[i];
            if(diff > maxi) maxi = diff;
        }
        
        long double low =0, high = maxi;
        while(high - low > 1e-6){
            long double mid = low + (high -low)/2.0;
            
            int cnt = func(stations,mid);
            if(cnt <= k) high = mid;
            else low = mid;
        }
        
        return high;
    }
};