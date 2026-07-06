// Last updated: 7/6/2026, 12:02:50 PM
class Solution {
public:
    // int profit;
    // int solve(vector<int>& prices, int ind, bool buy,vector<vector<int>>& dp){
    //     if(ind == prices.size()){ return 0; }

    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     if(buy){
    //         profit = max(-prices[ind] + solve(prices, ind+1, false,dp),solve(prices, ind+1,true,dp));
    //     }else{
    //         profit = max(
    //             prices[ind] + solve(prices, ind+1, true,dp),
    //             solve(prices, ind+1, false,dp)
    //         );
    //     }
    //     return dp[ind][buy] = profit;

    // }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        vector<int> prev(2,0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(2,0);
            curr[1] = max(
                -prices[i] + prev[0],
                prev[1]
            );

            curr[0] = max(
                prices[i] + prev[1],
                prev[0]
            );

            prev = curr;
        }

        return prev[1];
    }
};