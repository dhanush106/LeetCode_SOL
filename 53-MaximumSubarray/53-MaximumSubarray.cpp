// Last updated: 7/6/2026, 12:03:36 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        if(n==0) return 0;
        if(n == 1) return nums[0];
        for(int i=0;i<n;i++){
            if(sum<0){
                sum = 0;
            }
            sum+=nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};