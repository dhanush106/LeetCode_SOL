// Last updated: 7/6/2026, 12:02:25 PM
class Solution {
public:
    //Recursive Approach
    // int solve(vector<int>& nums, int ind){
    //     if(ind == 0) return nums[ind];
    //     if(ind<0) return 0;

    //     int pick = nums[ind] + solve(nums, ind-2);

    //     int notPick = 0 + solve(nums, ind-1);

    //     return max(pick, notPick);
    // }


    //Memoization
    // int solve(vector<int>& nums, vector<int>& dp, int ind){
    //     if(ind == 0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     int pick = nums[ind] + solve(nums, dp,ind-2);

    //     int notPick = 0 + solve(nums, dp, ind-1);

    //     return dp[ind] = max(pick, notPick);
    // }


    //Tabulation
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     dp[0] = nums[0];
    //     for(int i=1;i<n;i++){
    //         int pick = nums[i];
    //         if(i>1) pick+=dp[i-2];
    //         int notPick = dp[i-1];

    //         dp[i] = max(pick, notPick);
    //     }

    //     return dp[n-1];
    // }

    //Space optimization
    int rob(vector<int>& nums){
        int n= nums.size();
        int prev = nums[0] ,prev2 = 0;
        for(int i=1;i<n;i++){
            int num = nums[i];
            if(i>1){
                num+=prev2;
            }
            prev2 = prev;
            prev = max(num,prev2);
        }
        return prev;
    }
};