// Last updated: 7/6/2026, 12:02:28 PM
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n>0){
            if(n%2 == 1){
                ans++;
            }
            n=n/2;
        }
        return ans;
    }
};