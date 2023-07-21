class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto x : mp){
            pq.push({x.second,x.first});
        }
        vector<int> v;
        int cnt = 0;
        while(!pq.empty() && cnt<k){
            v.push_back(pq.top().second);
            pq.pop();
            cnt++;
        } 
        return v;
    }
};
