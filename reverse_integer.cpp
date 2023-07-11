class Solution {
public:
    int reverse(int x) {
        long int rev=0;
        long int num = abs(x);
        
        while(num>0){
            int digit=num%10;
            
            rev=rev*10+digit;
            num/=10;
        }
        if(rev>INT_MAX || rev<INT_MIN){
            return 0;
        }
        if( x>= 0){
            return rev;
        }
        return -rev;
    }
};
