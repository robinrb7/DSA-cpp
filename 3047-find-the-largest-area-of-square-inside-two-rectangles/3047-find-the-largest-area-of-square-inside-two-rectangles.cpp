class Solution {
private:
    long long solve(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight, int index1,int index2){
        int x3 = max(bottomLeft[index1][0],bottomLeft[index2][0]); 
        int x4 = min(topRight[index1][0],topRight[index2][0]);

        int y3 = max(bottomLeft[index1][1],bottomLeft[index2][1]); 
        int y4 = min(topRight[index1][1],topRight[index2][1]);

        if(x4<=x3 || y4<=y3) return 0;
        
        int width = x4-x3, height = y4-y3;

        long long side = min(width,height);
        return side;
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();

        long long maxSide = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long side = solve(bottomLeft,topRight,i,j);
                maxSide = max(maxSide,side);
            }
        }

        return (1ll*maxSide*maxSide);
    }
};