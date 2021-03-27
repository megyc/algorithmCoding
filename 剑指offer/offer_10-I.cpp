/**
 * 剑指 Offer 10- I. 斐波那契数列
*/
class Solution {
public:
    int fib(int n) {
        int a=0,b=1,sum;
        for(int i = 0;i < n;i++){
            sum = (a+b)%1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};