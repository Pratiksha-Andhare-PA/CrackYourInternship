class Solution {
public:

    int calDist(vector<int> &v1,vector<int> &v2){
        int dx = v2[0] - v1[0];
        int dy = v2[1] - v1[1];

        return dx*dx + dy*dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> dist;
        dist.insert(calDist(p1,p2));
        dist.insert(calDist(p1,p3));
        dist.insert(calDist(p1,p4));
        dist.insert(calDist(p2,p3));
        dist.insert(calDist(p2,p4));
        dist.insert(calDist(p3,p4));

        return dist.size() == 2 && !dist.count(0);
    }
};
