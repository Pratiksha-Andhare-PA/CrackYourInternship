class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mx = INT_MIN;

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int mxNum;
        for(auto num : mp){
            if(num.second > mx){
                mx = num.second;
                mxNum = num.first;
            }
        }
        return mxNum;
    }
};
