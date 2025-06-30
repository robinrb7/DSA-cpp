class Solution {
    int count = 0;
    private:
    void merge(vector<int>&arr,int low, int mid,int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;
    
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                count = count + (mid-left+1);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
                left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    
    void mergeSort(vector<int>&arr, int low, int high){
        if(low>=high) return;
        int mid = low + (high-low)/2;
        
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        mergeSort(arr,0,arr.size()-1);
        
        return count;
    }
};