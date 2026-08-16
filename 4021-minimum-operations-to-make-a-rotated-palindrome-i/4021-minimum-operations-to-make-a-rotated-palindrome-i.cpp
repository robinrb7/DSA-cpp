class Solution {
public:
    int minOperations(string s) {
        int n=s.length();

        int minOperations=INT_MAX;
        for(int i=0;i<n;i++){
            int currRotationRound = i;

            int operations = 0;
            for(int j=0;j<n/2;j++){
                int val1 = s[(currRotationRound + j) % n] -'a';
                int val2 = s[(currRotationRound + n-j-1) % n] -'a';

                int diff = abs(val1-val2);
                diff = min(diff,26-diff);

                operations += diff;
            }

            minOperations = min(minOperations,operations+i);
        }


        return minOperations;
    }
};