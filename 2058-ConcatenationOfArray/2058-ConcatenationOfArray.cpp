// Last updated: 7/6/2026, 12:00:35 PM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.size()*2);
        for(int i=0;i<nums.size()*2;i++){
            res[i] = nums[i%nums.size()];
        }
        return res;
        // for(int num : nums){
        //     if(nums.size() == 0) return nums;
        //     nums.push_back(num);
        // }
        // return nums;
    }
};