class Solution {
public:
    bool isHappy(int n) {
        set<int> calSum;
        int sum = 0;
        int num = n;
        while(true){
            sum = 0;
            while(num>0){
                int digit = num%10;
                num /= 10;
                sum += digit*digit;
            }
            if(sum == 1){
                return true;
            }
            if(calSum.count(sum) > 0){
                return false;
            }
            calSum.insert(sum);
            num = sum;
        }
        return false;
    }
};
