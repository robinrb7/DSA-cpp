class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();

        vector<int>left(n);

        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) left[i]=left[i-1] + 1;
            else left[i]=1;
        }

        int totalCandy = max(1,left[n-1]);
        int right = 1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) right =right + 1;
            else right=1;

            totalCandy += max(right,left[i]);
        }

        return totalCandy;
    }
};