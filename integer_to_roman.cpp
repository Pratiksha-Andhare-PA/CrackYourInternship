class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> mp;
        mp.insert({1, 'I'});
        mp.insert({5, 'V'});
        mp.insert({10, 'X'});
        mp.insert({50, 'L'});
        mp.insert({100, 'C'});
        mp.insert({500, 'D'});
        mp.insert({1000, 'M'});
        mp.insert({5000, 'G'});
        mp.insert({10000, 'H'});

        string s = to_string(num);
        int n = s.length();

        string res = "";
        for(int i=0;i<n;i++){
            int temp = (s[i] - '0');
            int ans = pow(10,n-i-1);
        

            if (temp == 9) {
                res.append(1, mp[ans]);
                res.append(1, mp[(temp+1) * ans]);
            }  
            else
            if (temp >= 5) {
                res.append(1, mp[5*ans]);
                res.append(temp-5, mp[ans]);
            }  
            else
            if (temp >= 4) {
                res.append(1, mp[ans]);
                res.append(1, mp[5*ans]);
            } 
            else {
                res.append(temp, mp[ans]);
            }
        }
        return res;
    }
};
