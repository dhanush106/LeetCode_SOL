// Last updated: 7/6/2026, 12:03:43 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        if(n<=1) return n;
        for(int j = 1; j < n; j++){
            if(nums[i] != nums[j]){
                i++;
            }
            nums[i]=nums[j];
        }
        return i + 1;
    }
};