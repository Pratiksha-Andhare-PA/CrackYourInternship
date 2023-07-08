class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        for(int i=0;i<strs[0].length();i++){
            char currChar = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != currChar || i >= strs[j].length()){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};
