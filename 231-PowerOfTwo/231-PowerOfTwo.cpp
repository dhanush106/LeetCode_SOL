// Last updated: 7/6/2026, 12:02:11 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && (n & n-1) == 0);
    }
};