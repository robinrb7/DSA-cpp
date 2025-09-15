class Solution {
private:
    bool isPossible(vector<int>&stations, int K,double mid){
        int partitions=0, n= stations.size();
        for(int i=0;i<n-1;i++){
            double dist = stations[i+1]-stations[i];
            if(dist>mid){
                partitions += (int)(dist/mid);
            }
            if(partitions>K) return 0;
        }
        return 1;
    }
  public:
    double minMaxDist(vector<int> &stations, int K) {
        int n =  stations.size();
        int maxDistance = INT_MIN;
        for(int i=0;i<n-1;i++){
            if(stations[i+1]-stations[i] > maxDistance) 
                maxDistance = stations[i+1]-stations[i];
        }
        
        double low = 0, high = maxDistance;
        while(high-low>1e-6){
            double mid = low + (high-low)/2.0;
            if(isPossible(stations,K,mid)){
                high = mid;
            }
            else low = mid;
        }
        
        return low;
    }
};