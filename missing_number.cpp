class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> freq(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans;
        for(int i=0;i<freq.size();i++){
            if(freq[i] == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
