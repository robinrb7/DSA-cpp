class Solution {
    private:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);

        int possibleCnt =1;
        int lastEndTime = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= lastEndTime){
                possibleCnt++;
                lastEndTime = max(lastEndTime,intervals[i][1]);
            }
        }

        return (n-possibleCnt);
    }
};