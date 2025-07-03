class Solution {
    private:
    int func(vector<int>&arr, int k, int maxPg){
        int n = arr.size();
        int cntSt=1, pgCnt=0;
        for(int i=0;i<n;i++){
            if(pgCnt + arr[i] > maxPg){
                cntSt++;
                pgCnt = 0;
            }
            pgCnt += arr[i];
            
        }
        return cntSt;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k>n) return -1;
        
        int sum=0, maxi = INT_MIN;
        for(int i =0;i<n;i++){
            if(arr[i] > maxi) maxi = arr[i];
            sum += arr[i];
        }
        
        int low = maxi, high = sum;
        
        while(low<=high){
            int mid = low +(high-low)/2;
            
            int cntSt = func(arr,k,mid);
            if(cntSt <= k){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
        
    }
};