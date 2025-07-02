class Solution {
    private:
    bool poss(vector<int> &position, int m, int force){
        int n = position.size();
        int ballCnt=1, last = position[0];
        for(int i =1;i<n;i++){
            if(position[i]-last >= force){
                ballCnt++;
                last = position[i];
            }
            if(ballCnt >= m) return 1;
        }
        return 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        
        int low =1, high = position[n-1] - position[0];
        while(low<=high){
            int mid = low +(high-low)/2;
            
            if(poss(position,m,mid)){
                low = mid+1;
            }
            else high = mid-1;
        }
        return high;
    }
};