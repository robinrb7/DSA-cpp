// User function template for C++

class Solution {
    int func(vector<vector<int>> &mat,int num){
        int n = mat.size();
        int m = mat[0].size();
        
        int cnt=0;
        for(int i =0;i<n;i++){
            int index = upper_bound(mat[i].begin(),mat[i].end(),num) - mat[i].begin();
            cnt += index;
        }
        
        return cnt;
    }
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int mini= INT_MAX, maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(mat[i][0]<mini) mini = mat[i][0];
            if(mat[i][m-1]>maxi) maxi = mat[i][m-1];
        }
        
        int low = mini, high = maxi;
        int numLeft = (n*m)/2;
        while(low<=high){
            int mid = low +(high-low)/2;
            
            int cnt = func(mat,mid);
            if(cnt >numLeft){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
        
    }
};
