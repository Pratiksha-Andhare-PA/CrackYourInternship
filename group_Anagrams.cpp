class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto word : strs){
            string sortedWord = word;
            sort(sortedWord.begin(),sortedWord.end());
            mp[sortedWord].push_back(word);
        }

        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
