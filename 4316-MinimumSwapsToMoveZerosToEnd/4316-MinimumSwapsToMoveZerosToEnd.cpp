// Last updated: 7/6/2026, 12:00:19 PM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        for(int i:nums){
            if(i == 0){
                zeroCount++;
            }
        }
        int count = 0;
        for(int i = n - zeroCount;i < n; i++){
            if(nums[i] != 0) count++;
        }
        return count;
    }
};