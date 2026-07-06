// Last updated: 7/6/2026, 12:00:50 PM
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[i]>nums[j]) count++;
            }
            res.push_back(count);
        }
        return res;
    }
};