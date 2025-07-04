// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n= arr.size();
        int m = arr[0].size();

        int rowIndex=-1, maxi=0;
        for(int i =0;i<n;i++){
            int cnt=0;

            int low =0, high = m-1;
            while(low<=high){
                int mid = low +(high-low)/2;

                if(arr[i][mid]==1) high = mid-1;
                else low = mid+1;
            }
            cnt = m-low;
            if(cnt>maxi){
                maxi = max(maxi,cnt);
                rowIndex = i;
            }
        }

        return rowIndex;
        
    }
};