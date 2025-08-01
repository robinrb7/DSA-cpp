class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int  n =nums.size();
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i = 0;i<k;i++){
            minHeap.push(nums[i]);
        }

        for(int i=k;i<n;i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};