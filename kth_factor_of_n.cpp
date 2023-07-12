class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> ans;
        ans.push_back(1);

        for(int i=2;i<n;i++){
            if(n%i == 0){
                ans.push_back(i);
            }
        }
        ans.push_back(n);

        if(ans.size() < k){
            return -1;
        }
        return ans[k-1];        
    }
};
