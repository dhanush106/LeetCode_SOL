// Last updated: 7/6/2026, 12:01:54 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n>0 && 1162261467%n == 0);
    }
};