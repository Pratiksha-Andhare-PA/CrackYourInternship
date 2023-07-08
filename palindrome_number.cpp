class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string si = str;
        reverse(str.begin(),str.end());
        if(str == si){
            return true;
        }
        return false;
    }
};
