class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();

        int totalCandy=1 , i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                totalCandy +=1;
                i++;
                continue;
            }

            int peak=1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                totalCandy += peak;
                i++;
            }

            int down=1;
            while(i<n && ratings[i] < ratings[i-1]){
                totalCandy += down;
                i++;
                down++;
            }
            if(down>peak) totalCandy += (down-peak);
        }

        return totalCandy;
    }
};