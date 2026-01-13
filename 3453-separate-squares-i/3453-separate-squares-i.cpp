class Solution {
    bool possible(double mid,vector<vector<int>>& squares){
        int n = squares.size();
        double upper=0.0, lower=0.0;
       
        for(int i=0;i<n;i++){
            double x = squares[i][0];
            double y = squares[i][1];
            double side = squares[i][2];

            double bottom = y, top = y+side;

            if(mid>=top) lower += (side*side);
            else if (mid<=bottom) upper += (side*side);
            else{
                double upperPart = top - mid;
                double lowerPart = mid - bottom;

                upper += (upperPart * side);
                lower += (lowerPart * side);
            }
            
        }

        return (lower >= upper);
        
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double low = INT_MAX, high = INT_MIN;
       
        for(int i=0;i<n;i++){
            double x = squares[i][0];
            double y = squares[i][1];
            double side = squares[i][2];

            low = min(low,y);
            high = max(high,y+side);
        }

        double maxi = high, mini = low;

        while(abs(low-high)>1e-6){
            double mid = low + (high-low)/2.0;

            if(possible(mid,squares)) high = mid;
            else low = mid;
        }
        return low;
    }
};