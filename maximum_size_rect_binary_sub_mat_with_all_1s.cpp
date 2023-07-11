#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define R 4
#define C 4

int mxArea(int heights[]) {
    //int n = heights.size();
    int maxArea = 0;
    stack<int> st;

    int tp;
    int areaWithTop;
    int i=0;
    while(i < C){
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

int maxRectArea(int arr[][C]){
    int result = mxArea(arr[0]);
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j] == 1 && i>1){
                arr[i][j] += arr[i-1][j];
            }
        }
        result = max(result,mxArea(arr[i]));
    }
    return result;
}


int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
 
    cout << "Area of maximum rectangle is "
         << maxRectArea(A);
 
    return 0;
}