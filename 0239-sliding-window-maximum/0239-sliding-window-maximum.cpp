class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n =nums.size();
        deque<int> dq;
        vector<int> res;

        for(int i=0;i<n;i++){
            while(!dq.empty() &&  i-k >= dq.front()) dq.pop_front();
            while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();

            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};