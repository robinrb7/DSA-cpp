class Solution {
    private:
    
    void merge(vector<int> &arr, int low,int mid,int high){
        int i = low, j=mid+1;
        vector<int> temp;

        while(i<=mid && j<=high){
            if(arr[i]<arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int k=low;k<=high;k++){
            arr[k] = temp[k-low];
        }
    }
    
    void mergeSortDivide(vector<int> &arr, int low, int high){
        if(low>=high) return;
        
        int mid = low + (high-low)/2;
        mergeSortDivide(arr,low,mid);
        mergeSortDivide(arr,mid+1,high);
        
        merge(arr,low,mid,high);
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        int n = arr.size();
        mergeSortDivide(arr,0,n-1);
        
    }
};