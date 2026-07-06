// Last updated: 7/6/2026, 12:03:22 PM
class Solution {
public:
    int climbStairs(int n) {
        // Tabulation ::: 
        // vector<int> dp(n+1,-1);
        // dp[0] = dp[1] = 1;

        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }

        // return dp[n];

        //Space Optimization
        int prev = 1, prev2 = 1;
        for(int i = 2;i<=n;i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};