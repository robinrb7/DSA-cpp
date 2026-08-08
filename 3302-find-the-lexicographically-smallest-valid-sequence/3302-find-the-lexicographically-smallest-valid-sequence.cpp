class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        int j=m-1;
        vector<int> last(m,-1);
        for (int i=n-1;i>=0;i--){
            if (j>=0 && word1[i]==word2[j]){
                last[j]=i;
                j--;
            }
        }
        j=0;
        int i=0;
        bool allow=1;
        vector<int>res;
        for (;i<n && j<m;i++){
            if (word1[i]==word2[j] || allow &&(j==m-1 || i+1 <= last[j+1])){
                res.push_back(i);
                if (word1[i]!=word2[j]){
                    allow=0;
                }
                j++;
            }
        }
        if (j==m) return res;
        return {};
    }
}; 