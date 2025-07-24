class Solution {
    const int MOD = (int)(1e9 +7);
    void prev(vector<int>& nums, vector<int> &pge,vector<int> &pse, int n){
        stack<int>stG,stS;

        for(int i=0;i<n;i++){
            while(!stS.empty() && nums[i]<nums[stS.top()])stS.pop();
            while(!stG.empty() && nums[i]>nums[stG.top()])stG.pop();

            if(stS.empty()) pse[i]=-1;
            else pse[i]=stS.top();

            if(stG.empty()) pge[i]=-1;
            else pge[i]=stG.top();

            stS.push(i);
            stG.push(i);
        }

    }
    void next(vector<int>& nums, vector<int> &nge,vector<int> &nse, int n){
        stack<int>stG,stS;

        for(int i=n-1;i>=0;i--){
            while(!stS.empty() && nums[i]<=nums[stS.top()])stS.pop();
            while(!stG.empty() && nums[i]>=nums[stG.top()])stG.pop();

            if(stS.empty()) nse[i]=n;
            else nse[i]=stS.top();

            if(stG.empty()) nge[i]=n;
            else nge[i]=stG.top();

            stS.push(i);
            stG.push(i);
        }

    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n =nums.size();

        vector<int>pse(n,-1);
        vector<int>nse(n,-1);

        vector<int>pge(n,-1);
        vector<int>nge(n,-1);

        prev(nums,pge,pse,n);
        next(nums,nge,nse,n);

        long long largest = 0;
        long long smallest =0;

        for(int i=0;i<n;i++){
            long long leftLargest = i - pge[i];
            long long rightLargest = nge[i] - i;
            largest += (leftLargest*rightLargest) * nums[i];

            long long leftSmallest = i - pse[i];
            long long rightSmallest = nse[i] - i;
            smallest += (leftSmallest*rightSmallest) * nums[i];
        }

        return (largest - smallest);
    }
};