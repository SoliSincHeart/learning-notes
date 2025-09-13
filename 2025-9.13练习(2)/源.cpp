class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        int arrows = 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
            });
        int arrow_pos = 0;
        for (int i = 0; i < points.size(); ) {
            arrow_pos = points[i][1];
            do {
                i++;
            } while (i < points.size() && points[i][0] <= arrow_pos);
            arrows++;
        }
        return arrows;
    }
};