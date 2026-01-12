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
                int yDiff = abs(currY - pointY);
                int xDiff = abs(currX - pointX);
                int movement = min(xDiff,yDiff);

                if(pointX>currX && pointY>currY){
                    currX +=movement, currY+=movement;
                }
                else if(pointX<currX && pointY>currY){
                    currX -=movement, currY+=movement;
                }
                else if(pointX<currX && pointY<currY){
                    currX -=movement, currY-=movement;
                }
                else {
                    currX +=movement, currY-=movement;
                }

                totalTime+=movement;
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