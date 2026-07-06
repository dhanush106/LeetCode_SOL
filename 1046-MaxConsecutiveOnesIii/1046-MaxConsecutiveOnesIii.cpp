// Last updated: 7/6/2026, 2:11:53 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int sum = 0, n = nums.size();
        int zero = 0;
        int maxlen = 0;
        while (r < n) {
            if(nums[r] == 0){
                zero++;
            }

            while(zero>k){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }

            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};