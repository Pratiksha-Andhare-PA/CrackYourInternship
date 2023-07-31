class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_count;
        for (char c : t) {
            t_count[c]++;
        }

        int left = 0, right = 0;
        int min_window = INT_MAX;
        int min_window_start = 0;
        int required_chars = t.size();

        while (right < s.size()) {
            if (t_count.find(s[right]) != t_count.end()) {
                t_count[s[right]]--;
                if (t_count[s[right]] >= 0) {
                    required_chars--;
                }
            }

            while (required_chars == 0) {
                if (right - left + 1 < min_window) {
                    min_window = right - left + 1;
                    min_window_start = left;
                }

                if (t_count.find(s[left]) != t_count.end()) {
                    t_count[s[left]]++;
                    if (t_count[s[left]] > 0) {
                        required_chars++;
                    }
                }

                left++;
            }

            right++;
        }

        if (min_window == INT_MAX) {
            return "";
        }
        return s.substr(min_window_start, min_window);
    }
};
