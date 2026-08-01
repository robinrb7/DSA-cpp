class Solution {
    private:
    int solve(vector<int>& nums, int start, int end){
        if(start==end){
            return nums[start]; // or nums[end] -> both same as index is same, but we are taking it
                                //because this value has not been included yet in any player's score.
        }

        int takeStart = nums[start] - solve(nums,start+1,end);
        int takeEnd = nums[end] - solve(nums,start,end-1);

        return max(takeStart, takeEnd);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        int playerFirstMaxScore = solve(nums,0,n-1);
        return (playerFirstMaxScore>=0) ;
    }
};