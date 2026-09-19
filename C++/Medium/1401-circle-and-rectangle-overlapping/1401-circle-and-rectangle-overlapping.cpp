class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xDist=max(x1,min(xCenter,x2)) - xCenter;
        int yDist=max(y1,min(yCenter,y2)) - yCenter;

        if(xDist * xDist + yDist * yDist <= radius * radius)
            return true;
        else 
            return false;
    }
};