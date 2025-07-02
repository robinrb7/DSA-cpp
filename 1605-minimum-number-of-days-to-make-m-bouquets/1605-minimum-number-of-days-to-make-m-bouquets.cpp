class Solution {
    private:
    int func(vector<int> &bloom,int k, int n,int mid){
        int bq = 0, cnt =0;
        for(int i =0;i<n;i++){
            if(mid >= bloom[i]){
                cnt++;
            }
            else{
                bq += cnt/k;
                cnt =0;
            }
        }
        if(cnt > 0) bq += cnt/k;

        return bq;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1ll*m*k > n) return -1;

        int mini=INT_MAX, maxi = INT_MIN;
        for(int i =0;i<n;i++){
            if(bloomDay[i]>maxi) maxi = bloomDay[i];
            if(bloomDay[i]<mini) mini = bloomDay[i];
        }

        int low = mini, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;

            int bq = func(bloomDay,k,n,mid);
            if(bq >= m){
                high = mid -1;
            }
            else low = mid+1;
        }

        return low;
    }
};