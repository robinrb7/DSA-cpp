class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int cnt5 =0, cnt10=0, cnt20=0;

        for(int i=0;i<n;i++){
            if(bills[i]==5) cnt5++;
            else if(bills[i]==10){
                cnt10++;
                if(cnt5>0) cnt5--;
                else return false;
            }
            else{
                cnt20++;
                if(cnt5>0) cnt5--;
                else return false;

                if(cnt10>0) cnt10--;
                else if(cnt5 >= 2) cnt5 = cnt5-2;
                else return false;
            }
        }

        return true;
    }
};