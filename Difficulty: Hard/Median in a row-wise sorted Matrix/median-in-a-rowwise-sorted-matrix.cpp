// User function template for C++

class Solution {
    private:
    int upperB(vector<int>arr,int mid){
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid) return i;
        }
        
        return arr.size();
    }
    int getSmall(vector<vector<int>> &mat, int mid){
        int ans = 0;
        for(int i=0;i<mat.size();i++){
            ans += upperB(mat[i],mid);
        }
        
        return ans;
    }
    
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m  = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(mat[i][0] < low) low = mat[i][0];
            if(mat[i][m-1] > high) high = mat[i][m-1];
        }
        
        
        int total = (m*n)/2;
        while(low<=high){
            int mid = low + (high-low)/2;
            int smallerEqual = getSmall(mat,mid);
            
            if(smallerEqual <= total) low = mid+1;
            else high = mid -1;
        }
        return low;
        
    }
};
