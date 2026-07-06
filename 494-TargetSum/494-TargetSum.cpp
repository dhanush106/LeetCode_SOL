// Last updated: 7/6/2026, 12:01:33 PM
class Solution {
public:
    // int solve(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset){
    //     if(i == nums.size()){
    //         return (sum == target);
    //     }

    //     if(dp[i][sum + offset] != -1){
    //         return dp[i][sum+offset];
    //     }

    //     int plus = solve(i+1, sum+nums[i],nums,target,dp,offset);
    //     int minus = solve(i+1, sum-nums[i],nums,target,dp,offset);

    //     return dp[i][sum+offset] = plus+minus;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int x : nums)
            total += x;
        
        if(abs(target) > total)
            return 0;

        int offset = total;
        vector<vector<int>> dp(n+1,vector<int>(2 * total + 1, 0));
        for(int i=0;i<n;i++){
            for(int j=-total;j<=total;j++){
                if(i==0){
                    dp[i][offset] = 1;
                }
                if(dp[i][j+offset] == 0){
                    continue;
                }

                dp[i+1][j+nums[i]+offset] += dp[i][offset+j];
                dp[i+1][j-nums[i]+offset] += dp[i][offset+j];
            }
        }

        return dp[n][target+offset];
    }
};