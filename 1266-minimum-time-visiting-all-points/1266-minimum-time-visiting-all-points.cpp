class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 0;

        int totalTime = 0;
        int currX = points[0][0], currY = points[0][1];

        for(int i=1;i<n;i++){
            int pointX = points[i][0], pointY = points[i][1];

            while(currX != pointX && currY != pointY){
                if(pointX>currX && pointY>currY){
                    currX +=1, currY+=1;
                }
                else if(pointX<currX && pointY>currY){
                    currX -=1, currY+=1;
                }
                else if(pointX<currX && pointY<currY){
                    currX -=1, currY-=1;
                }
                else {
                    currX +=1, currY-=1;
                }

                totalTime+=1;
            }

            if(currX==pointX){
                totalTime += (abs(currY - pointY));
                currY = pointY;
            }
            else {
                totalTime += (abs(currX-pointX));
                currX = pointX;
            } 
        }

        return totalTime;
    }
};