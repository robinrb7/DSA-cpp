class Solution {
    int solveTab(string s1,string s2){
        int n = s1.length();
        vector<int>prev(n+1,0);

        for(int index1=1;index1<=n;index1++){
            int prevDg=0;
            for(int index2=1;index2<=n;index2++){
                int ans=0;
                if(s1[index1-1]==s2[index2-1]){
                    ans = 1 + prevDg;
                }
                else{
                    ans = max(prev[index2-1],prev[index2]);
                }
                prevDg = prev[index2];
                prev[index2] = ans;
            }
        }

        return prev[n];
    }
public:
    int minInsertions(string s) {
        string s1=s, s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.length();

        return  n - solveTab(s1,s2);
    }
}; 