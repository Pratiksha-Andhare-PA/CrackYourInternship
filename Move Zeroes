class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                v.push_back(nums[i]);
            }
        }

        for(int i=v.size();i<n;i++){
            nums[i] = 0;
        }

        for(int i=0;i<v.size();i++){
            nums[i] = v[i];
        }
    }
};
