// Last updated: 7/6/2026, 12:02:34 PM
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(auto c: columnTitle) {
            int x = c - 'A' + 1;
            ans = ans * 26 + x;
        }
        return ans;
    }
};