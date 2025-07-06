class Solution {
  public:
    string maxOdd(string s) {
        int n=s.length();
        
        int i=0,j=n-1;
        
        while(i<n && s[i]==0) i++;
        while(j>=0 && s[j]%2==0) j--;
        
        return s.substr(i,j-i+1);
        
    }
};