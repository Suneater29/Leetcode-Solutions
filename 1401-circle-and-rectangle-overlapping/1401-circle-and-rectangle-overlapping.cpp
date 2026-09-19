class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x;
        if(xCenter<x1) x=x1;
        else if(xCenter>x2) x=x2;
        else x=xCenter;
        int y;
        if(yCenter<y1) y=y1;
        else if(yCenter>y2) y=y2;
        else y=yCenter;
        int dx=xCenter-x;
        int dy=yCenter-y;
        if((dx*dx)+(dy*dy)<=(radius*radius)) return true;
        return false;
    }
};