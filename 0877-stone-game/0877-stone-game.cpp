class Solution {
    private:
    int solve(vector<int>& piles, int start, int end){
        if(start>end) return 0;

        int takeStart = piles[start] - solve(piles,start+1,end);
        int takeEnd = piles[end] - solve(piles,start,end-1);

        return max(takeStart,takeEnd);
    }

    int solveOptm(vector<int>& piles){
        int n = piles.size();
        vector<int> curr(n+1,0);

        for(int start=n-1;start>=0;start--){
            curr[start+1] = piles[start];
            for(int end=start+1;end<n;end++){

                int takeStart = piles[start] - curr[end+1];
                int takeEnd = piles[end] - curr[end];
                curr[end+1] = max(takeStart, takeEnd);
            }
        }
        
        return curr[n];
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int playerFirstMaxScore = solveOptm(piles);
        return playerFirstMaxScore > 0;
    }
};