class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        int tp;
        int areaWithTop;
        int i=0;
        while(i < n){
            if(st.empty() || heights[st.top()] <= heights[i]){
                st.push(i);
                i++;
            }
            else{
                tp = st.top();
                st.pop();
                areaWithTop = heights[tp] * (st.empty() ? i : i-st.top()-1);

                if(areaWithTop > maxArea){
                    maxArea = areaWithTop;
                }
            }
        }
        while(!st.empty()){
            tp = st.top();
            st.pop();
            areaWithTop = heights[tp] * (st.empty() ? i : i-st.top()-1);

            if(areaWithTop > maxArea){
                maxArea = areaWithTop;
            }
        }
        return maxArea;
    }
};
