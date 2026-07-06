// Last updated: 7/6/2026, 12:02:03 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int tot = (n*(n+1))/2;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return tot-sum;
    }
};