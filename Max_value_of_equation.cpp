class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq; // Store pairs (yi - xi, xi)
        int max_val = INT_MIN;

        for (const auto& point : points) {
            int xi = point[0];
            int yi = point[1];

            // Remove points outside the window (|xi - xj| > k)
            while (!dq.empty() && xi - dq.front().second > k) {
                dq.pop_front();
            }

            // Update the maximum value within the window
            if (!dq.empty()) {
                int current_val = dq.front().first + xi + yi;
                max_val = max(max_val, current_val);
            }

            // Remove points with smaller yi - xi values as they won't contribute to a higher sum
            while (!dq.empty() && yi - xi >= dq.back().first) {
                dq.pop_back();
            }

            // Add the current point to the deque
            dq.push_back(make_pair(yi - xi, xi));
        }

        return max_val;
    }
};
