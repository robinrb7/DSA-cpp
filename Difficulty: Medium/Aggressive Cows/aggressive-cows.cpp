// User function Template for C++

class Solution {
    private:
    bool poss(vector<int> &stalls, int k, int dist){
        int n = stalls.size();
        int cowCnt=1, last = stalls[0];
        for(int i =1;i<n;i++){
            if(stalls[i]-last >= dist){
                cowCnt++;
                last = stalls[i];
            }
            if(cowCnt >= k) return 1;
        }
        return 0;
    }
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        
        int low =1, high = stalls[n-1] - stalls[0];
        while(low<=high){
            int mid = low +(high-low)/2;
            
            if(poss(stalls,k,mid)){
                low = mid+1;
            }
            else high = mid-1;
        }
        return high;
        
    }
};