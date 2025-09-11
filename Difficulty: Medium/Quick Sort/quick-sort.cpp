class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
       int n = arr.size();
       if(low<high){
           int partitionIndex = partition(arr,low,high);
           quickSort(arr,low,partitionIndex-1);
           quickSort(arr,partitionIndex+1,high);
       }
       
       return;
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivotIndex=low;
        int i=low, j=high;
        
        while(i<j){
            while(arr[i]<=arr[pivotIndex] && i<=high-1) i++;
            while(arr[j]>arr[pivotIndex] && j>=low+1) j--;
            
            if(i<j) swap(arr[i],arr[j]);
        }
        
        swap(arr[pivotIndex],arr[j]);
        return j;
    }
};