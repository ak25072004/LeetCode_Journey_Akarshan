class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(begin(points), end(points));
        int last = points[0][0], rectangles = 0;

        for(int i=1; i<points.size(); i++){
            if(points[i][0] - last <= w) continue;
            else{
                rectangles++;
                last = points[i][0];
            } 
        }

        return rectangles + 1;
    }
};