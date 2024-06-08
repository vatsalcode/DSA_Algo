class Solution {
public:

    int helper(int a, int b){
        while(b!=0){
            unsigned c=(a&b);
            a=a^b;
            b=c<<1;
        }

        return a;
    }
    int getSum(int a, int b) {
       return helper(a,b);
    }
};