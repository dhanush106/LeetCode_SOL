// Last updated: 7/6/2026, 12:02:32 PM
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        for(int i=5;i<=n;i=i*5){
            res=res+n/i;
        }
        return res;
    }
};