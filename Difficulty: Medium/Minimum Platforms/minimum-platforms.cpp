class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int maxPlatformsRequired = 0, cnt=0;
        int i=0,j=0;
        
        while(i<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            maxPlatformsRequired = max(maxPlatformsRequired,cnt);
        }
        
        return maxPlatformsRequired;
    }
};
