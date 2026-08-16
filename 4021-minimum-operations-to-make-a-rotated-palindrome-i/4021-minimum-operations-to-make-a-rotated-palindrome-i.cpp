class Solution {
public:
    int minOperations(string s) {
        int n=s.length();

        int minOperations=INT_MAX;
        for(int i=0;i<n;i++){

            int operations = 0;
            for(int j=0;j<n/2;j++){
                int forwardDiff = (s[j]-s[n-j-1]+26)%26;
                int backwardDiff = (s[n-j-1]-s[j]+26)%26;

                int diff = min(forwardDiff,backwardDiff);
                operations += diff;
            }

            minOperations = min(minOperations,operations+i);

            char ch = s[0];
            s = s.substr(1,n-1);
            s.push_back(ch);

        }


        return minOperations;
    }
};