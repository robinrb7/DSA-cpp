class Solution {
  public:
    int binaryToDecimal(string &b) {
        int len = b.length();
        int power2=1;
        int result = 0;
        
        for(int i=len-1;i>=0;i--){
            if(b[i]=='1'){
                result += power2; 
            }
            power2 = power2 * 2;
        }
        
        return result;
    }
};