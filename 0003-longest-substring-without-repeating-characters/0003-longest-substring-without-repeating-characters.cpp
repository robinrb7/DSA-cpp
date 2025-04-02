class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int>umap;
        int len=0,maxi=0;

        int left=0,right=0;
        while(right<n){
            if(umap.find(s[right]) != umap.end()){
                left = max(umap[s[right]] + 1,left);
            }
            len = right-left+1;
            maxi=max(maxi,len);
            umap[s[right]]=right;
            right++;
        }
        
        return maxi;
    }
};