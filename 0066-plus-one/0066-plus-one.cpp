class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]==9){
            int index = n-1;
            while(index>0 && digits[index-1]==9){
                digits[index--]=0;
            }

            digits[index]=1;
            digits.push_back(0);
        }
        else digits[n-1]++;

        return digits;
    }
};