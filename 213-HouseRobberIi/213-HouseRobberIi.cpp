// Last updated: 7/6/2026, 12:02:16 PM
class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int start, int end){
    //    if(end==start) return nums[start];
    //    if(end<start) return 0;
    //    if(dp[end] != -1) 
    //     int notPick = solve(nums,start,end-1);
    //     int pick = nums[end];
    //     if(end>1){
    //         pick += solve(nums,start,end-2);
    //     }
    //     return max(pick, notPick)
    dp[start]=nums[start];
   for(int ind=start+1;ind<=end;ind++)
   {

    int np=dp[ind-1];
    int pick=nums[ind];
    if(ind-2>=start)
    {
        pick+=dp[ind-2];
    }
    dp[ind]=max(pick,np);

   }
return dp[end];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        int b = solve(nums, dp, 0, n-2);
        int a = solve(nums, dp, 1, n-1);
        return max(a,b);
    }
};