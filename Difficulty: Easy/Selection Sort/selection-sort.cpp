class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            int j = i+1;
            int minIndex = i;
            while(j<n){
                if(arr[j]<arr[minIndex]) minIndex = j;
                j++;
            }
            
            if(minIndex!=i) swap(arr[i],arr[minIndex]);
        }
    }
};