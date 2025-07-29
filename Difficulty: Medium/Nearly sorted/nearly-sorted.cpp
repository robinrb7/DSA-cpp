class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n =arr.size();
        
        int j=0;
        priority_queue<int,vector<int>,greater<int>> minHeap;
         for(int i=0;i<n;i++){
             minHeap.push(arr[i]);
             if(minHeap.size() > k){
                 arr[j] = minHeap.top();
                 minHeap.pop();
                 j++;
             } 
         }
         
         while(!minHeap.empty() && j<n){
            arr[j] = minHeap.top();
            minHeap.pop();
            j++;
         }
    }
};