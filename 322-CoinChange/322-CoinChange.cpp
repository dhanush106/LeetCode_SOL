// Last updated: 7/6/2026, 12:01:56 PM
class Solution {
public:
    // int solve(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp){
      
    //     if(ind == 0){
    //         if(amount%coins[0] == 0){
    //             return amount/coins[0];
    //         }
    //         return INT_MAX;
    //     }

    //     if(dp[ind][amount] != -1){
    //         return dp[ind][amount];
    //     }

    //     int notPick = solve(coins, amount, ind-1, dp);
    //     int pick = INT_MAX;
    //     if(amount>=coins[ind]){
    //         pick = 1+solve(coins,amount-coins[ind], ind, dp);
    //     }

    //     return dp[ind][amount] = min(pick, notPick);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<=amount;j++){
    //             if(i==0){
    //                 if(j%coins[i] == 0){
    //                     dp[i][j] = j/coins[i];
    //                 }else{
    //                     dp[i][j] = 1e9;
    //                 }
    //             }else{
    //                 int notPick = dp[i-1][j];
    //                 int pick = 1e9;
    //                 if(j>=coins[i]){
    //                     pick = 1 + dp[i][j-coins[i]];
    //                 }
    //                 dp[i][j] = min(pick, notPick);
    //             }
    //         }
    //     }

    //     return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount];
    // }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        for(int i=0;i<n;i++){
            vector<int> curr(amount+1,0);
            for(int j=0;j<=amount;j++){
                if(i==0){
                    if(j%coins[i] == 0){
                        curr[j] = j/coins[i];
                    }else{
                        curr[j] = 1e9;
                    }
                }else{
                    int notPick = prev[j];
                    int pick = 1e9;
                    if(j>=coins[i]){
                        pick = 1 + curr[j-coins[i]];
                    }
                    curr[j] = min(pick, notPick);
                }
            }
            prev = curr;
        }
        return (prev[amount] == 1e9) ? -1 : prev[amount];
    }
};