class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && nums[i] == nums[j]){
                    return nums[i];
                }
            }
        }
        return -1;
    }
};
