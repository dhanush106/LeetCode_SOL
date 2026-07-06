// Last updated: 7/6/2026, 12:01:02 PM
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int a = fib(n-1)+fib(n-2);
        return a;
    }
};