class Solution {
public:
    void backtrack(vector<string> &ans,string curr,int openCnt, int closedCnt, int n){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }

        if(openCnt < n){
            curr.push_back('(');
            backtrack(ans,curr,openCnt+1,closedCnt,n);
            curr.pop_back();
        }
        if(closedCnt < openCnt){
            curr.push_back(')');
            backtrack(ans,curr,openCnt,closedCnt+1,n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        backtrack(ans,curr,0,0,n);
        return ans;
    }
};
