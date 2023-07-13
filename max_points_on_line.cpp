class Solution {
public:

    double getSlope(const vector<int>& p1, const vector<int>& p2) {
        if (p1[0] == p2[0]) {
            return numeric_limits<double>::infinity(); 
        } 
        else {
            return static_cast<double>(p2[1] - p1[1]) / (p2[0] - p1[0]); 
        }
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) {
            return n; 
        }

        int maxPointsCount = 0; 

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> slopeCount;
            int duplicatePoints = 1; 

            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    duplicatePoints++;
                } else {
                    double slope = getSlope(points[i], points[j]);
                    slopeCount[slope]++;
                }
            }

            int currentMax = duplicatePoints; 
            for (auto& entry : slopeCount) {
                currentMax = max(currentMax, entry.second + duplicatePoints);
            }

            maxPointsCount = max(maxPointsCount, currentMax);
        }

        return maxPointsCount;
    }
};
