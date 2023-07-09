class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int start = 0;
        int end = height.size()-1;

        while(start < end){
            int currArea = (end-start)*min(height[start],height[end]);
            if(currArea > maxArea){
                maxArea = currArea;
            }
            if(height[start] < height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxArea;
    }
};
