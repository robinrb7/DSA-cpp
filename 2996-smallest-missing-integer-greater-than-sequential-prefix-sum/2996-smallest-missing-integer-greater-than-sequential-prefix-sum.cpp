class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]+1;

        vector<int> present(51,0);
        for(int i=0;i<n;i++) present[nums[i]]=1;

        int sum=nums[0];
        int i=1;
        while(i<n){
            if(nums[i]!=nums[i-1]+1) break;

            sum +=nums[i];
            i++;
        }

        int potSmallestMissing=sum;
        while(potSmallestMissing<51 && present[potSmallestMissing]){
            potSmallestMissing++;
        }

        return potSmallestMissing;  
    }
};