class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        
        int x = n/8;
        int y = n%8;

        int num = (x *(x+1))/2;
        int ans = num * 8 + y*(x+1);

        return ans;
    }

 
};

   