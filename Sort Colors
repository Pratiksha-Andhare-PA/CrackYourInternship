class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                cnt0++;
            }
            else if(nums[i] == 1){
                cnt1++;
            }
            if(nums[i] == 2){
                cnt2++;
            }
        }

        int i,j;
        for(i=0;i<cnt0;i++){
            nums[i] = 0;
        }
        for(j=i;j<cnt1+cnt0;j++){
            nums[j] = 1;
        }
        for(int k=j;k<n;k++){
            nums[k] = 2;
        }
    }
};
