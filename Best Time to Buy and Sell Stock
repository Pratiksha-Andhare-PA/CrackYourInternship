class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = prices[i];
        }
        sort(v.begin(),v.end(),greater<int>());

        bool flag = true;    
        for(int i=0;i<n;i++){
            if(v[i] != prices[i]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            return 0;
        }
        
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else{
                int currProfit = prices[i] - minPrice;
                if(maxProfit < currProfit){
                    maxProfit = currProfit;
                }
            }
        }
        return maxProfit;
    }
};
