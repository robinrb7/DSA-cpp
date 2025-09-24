class Solution {
  public:
    int binaryToDecimal(string &b) {
        int  n = b.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(b[i]=='1'){
                ans += 1 << (n-1-i);
            }
        }
        
        return ans;
    }
};