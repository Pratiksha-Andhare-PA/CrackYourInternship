class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        
        int diff = abs(n1 - n2);
        if (n1 > n2) {
            b = string(diff, '0') + b;
        } else {
            a = string(diff, '0') + a;
        }
        char carry = '0';
        string res;
        for(int i=max(n1,n2)-1;i>=0;i--){
            if(a[i]=='1' && b[i]=='1'){
                if(carry == '0'){
                    res.push_back('0');
                    carry = '1';
                }
                else{
                    res.push_back('1');
                    carry = '1';
                }
            }
            else if(a[i] == '0' && b[i] == '0'){
                if(carry == '0'){
                    res.push_back('0');
                    carry = '0';
                }
                else{
                    res.push_back('1');
                    carry = '0';
                }
            }
            else if(a[i] != b[i]){
                if(carry == '0'){
                    res.push_back('1');
                    carry = '0';
                }
                else{
                    res.push_back('0');
                    carry = '1';
                }
            }
        }
        if(carry == '1'){
            res.push_back('1');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
