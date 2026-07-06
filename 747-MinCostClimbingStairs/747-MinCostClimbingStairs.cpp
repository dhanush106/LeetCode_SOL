// Last updated: 7/6/2026, 12:01:08 PM
class Solution {
public:
    // int solve(vector<int>& cost, vector<int>& dp, int ind){
    //     if(ind>=cost.size()) return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     int left = solve(cost, dp, ind+1) + cost[ind];
    //     int right = INT_MAX;
    //     // if(i)
    //     right = solve(cost, dp, ind+2) + cost[ind];

    //     return dp[ind] = min(left,right);
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n,-1);
    //     int a = solve(cost,dp,0);
    //     int b = solve(cost,dp,1);
    //     return min(a,b);
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]

        for (int i = n - 1; i >= 0; i--) {
            int curr = cost[i] + min(next1, next2);
            next2 = next1;
            next1 = curr;
        }

        return min(next1, next2);
    }
};