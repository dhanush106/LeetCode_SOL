// Last updated: 7/6/2026, 12:01:52 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
    return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555);
    }
};