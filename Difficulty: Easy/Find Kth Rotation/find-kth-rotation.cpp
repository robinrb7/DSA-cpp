// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low =0,high=n-1;

        while(low < high){
            int mid = low + (high-low)/2;

            if(arr[low] <= arr[high]) return low;

            if(arr[mid] >= arr[0]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }

        return low;
        
    }
};
