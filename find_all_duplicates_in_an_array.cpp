class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] > mx){
                mx = nums[i];
            }
        }
        vector<int> freq(mx+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<=mx;i++){
            if(freq[i] == 2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
