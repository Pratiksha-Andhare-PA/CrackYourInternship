class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            for(int l=i+1;l<n-2;l++){
                int j=i+1;
                int k=n-1;

                while(j < k){
                    int sum = nums[i]+nums[l]+nums[j]+nums[k];
                    if(sum == target){
                        s.insert({nums[i],nums[l],nums[j],nums[k]});
                        j++;
                        k--;
                    }
                    else if(sum < target){
                        j++;
                    }
                    else{
                        k--;
                    }
                }
            }
        }
        vector<vector<int>> v;
        for(auto x : s){
            v.push_back(x);
        }
        return v;
    }
};
