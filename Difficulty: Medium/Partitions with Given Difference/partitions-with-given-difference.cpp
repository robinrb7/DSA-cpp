class Solution {
    private:
    int solve(vector<int> &arr, int index, int target){
        if(index==0){
            if(arr[0]==0 && target==0) return 2;
            if(arr[0]==target || target==0) return 1;
            return 0;
        }
        
        int notTake = solve(arr,index-1,target);
        int take =0;
        if(arr[index]<=target) take = solve(arr,index-1,target-arr[index]);
        
        return take + notTake;
    }
    
    int solveTab(vector<int> &arr,int sum){
        int n =arr.size();
        vector<int>prev(sum+1,0);
        vector<int>curr(sum+1,0);
        
        if(arr[0]<=sum) prev[arr[0]]=1;
        if(arr[0]==0) prev[0]=2;
        else prev[0]=1;
        
        for(int index=1;index<n;index++){
            for(int target=0;target<=sum;target++){
                int notTake = prev[target];
                int take =0;
                if(arr[index]<=target) take = prev[target-arr[index]];
                
                curr[target] = take + notTake;
            }
            prev = curr;
        }
        
        return prev[sum];
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = 0;
        for(int x: arr) totalSum +=x;
        
        if(totalSum-d <0 || (totalSum-d)%2==1) return 0;
        int target = (totalSum-d)/2;
        return solveTab(arr,target);
    }
};