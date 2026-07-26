class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1=series1.size(), n2 = series2.size();
        //int start1 = 0, start2=0, end1=series1.size()-1, end2=series2.size()-1;

        vector<vector<int>> ans;

        int pointer1=0, pointer2=0;
        while(pointer1<n1 && pointer2<n2){
            if(series1[pointer1][0] == series2[pointer2][0]){
                ans.push_back({series1[pointer1][0], series1[pointer1][1] + series2[pointer2][1]});
                pointer1++,pointer2++;
            }
            else if(series1[pointer1][0] < series2[pointer2][0]){
                ans.push_back({series1[pointer1][0], series1[pointer1][1] + series2[pointer2][1]});
                pointer1++;
            }
            else{
                ans.push_back({series2[pointer2][0], series1[pointer1][1] + series2[pointer2][1]});
                pointer2++;
            }
        }

        while(pointer1<n1){
            ans.push_back({series1[pointer1][0], series1[pointer1][1]});
            pointer1++;
        }

        while(pointer2<n2){
            ans.push_back({series2[pointer2][0], series2[pointer2][1]});
            pointer2++;
        }


        return ans;
    }
};