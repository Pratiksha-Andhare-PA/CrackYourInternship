#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string ans = "";

        int i = 0;
        while (i < path.length()) {
            // Skip leading slashes
            while (i < path.length() && path[i] == '/')
                i++;

            // Extract the directory/file name
            string name = "";
            while (i < path.length() && path[i] != '/')
                name += path[i++];

            // Handle different elements
            if (name == "..") {
                if (!s.empty())
                    s.pop();
            } else if (name != "." && !name.empty()) {
                s.push(name);
            }
        }

        // Construct the simplified canonical path
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        // Handle the case when the path is empty
        if (ans.empty())
            ans = "/";

        return ans;
    }
};
