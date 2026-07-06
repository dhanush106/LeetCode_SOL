// Last updated: 7/6/2026, 12:01:26 PM
class Solution {
public:
    // int solve(int amount, vector<int>& coins, int ind,vector<vector<int>>& dp){
    //     if(ind == 0){
    //         if(amount % coins[ind] == 0) return 1;
    //         return 0;
    //     }

    //     if(dp[ind][amount] != -1) return dp[ind][amount];

    //     int notPick = solve(amount,coins,ind-1,dp);
    //     int pick = 0;
    //     if(amount>=coins[ind]){
    //         pick += solve(amount-coins[ind],coins,ind,dp);
    //     }
    //     return dp[ind][amount] = pick+notPick;
    // }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                    if(j % coins[0] == 0)
                        dp[0][j] = 1;
                    else
                        dp[0][j] = 0;
                }else{
                    int notPick = dp[i-1][j];
                    int pick = 0;
                    if(j>=coins[i]){
                        pick += dp[i][j-coins[i]];
                    }

                    dp[i][j] = (long long)pick + (long long)notPick;
                }
            }
        }

        return dp[n-1][amount];
    }
};