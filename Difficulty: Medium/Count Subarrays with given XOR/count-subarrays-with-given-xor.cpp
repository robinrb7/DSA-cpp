class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        
        unordered_map<int,int> hash;
        hash[0]=1;
        int xr =0;
        long long int count = 0;
        
        for(int i =0;i<n;i++){
            xr = xr^arr[i];
            
            count  += hash[xr^k];
            
            hash[xr]++;
        }
        
        return count;
    }
};