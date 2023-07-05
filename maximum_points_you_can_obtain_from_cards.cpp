class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        
        for(int i=n-k;i<n;i++){
            sum += cardPoints[i];
        }
        int mxSum = sum;

        for(int i=1;i<=k;i++){
            sum = sum + cardPoints[i-1] - cardPoints[n-k+i-1];
            mxSum = max(mxSum,sum);
        }
        return mxSum;
    }
};
