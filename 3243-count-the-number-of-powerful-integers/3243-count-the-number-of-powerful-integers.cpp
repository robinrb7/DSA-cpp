class Solution {
    private:
    long long solve(string str, string suffix, int limit){
        if(str.length() < suffix.length()) return 0;

        int remainLen = str.length() - suffix.length();
        long long count=0;
        for(int i =0;i<remainLen;i++){
            int digit = str[i] - '0';
            if(digit<= limit){
                count += digit * pow(limit+1,remainLen-i-1);
            }
            else{
                count +=  pow(limit+1,remainLen-i);
                return count;
            }
        }

        string trailStr = str.substr(str.length() - suffix.length());
        if(trailStr >= suffix) count++;

        return count;

    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);

        return solve(finishStr,s,limit) - solve(startStr,s,limit);
    }
};