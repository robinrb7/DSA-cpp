class Solution {
    private:
    bool poss(vector<int>& weights, int days, int capacity){
        int n = weights.size();
        int sum = 0, cntD=1;
        for(int i =0;i<n;i++){
            if(weights[i] > capacity) return 0;
            
            if(sum + weights[i] > capacity){
                cntD++;
                sum = 0;
            }
            sum += weights[i];
            if(cntD > days) return 0;
        }
        return 1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum += weights[i];
        }

        int low = 1,high=sum;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(poss(weights,days,mid)){
                high = mid-1;
            }
            else  low=mid+1;
        }
        return low;
    }
};