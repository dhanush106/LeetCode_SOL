// Last updated: 7/6/2026, 12:00:31 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int pos = 0,neg = 1;
        for(int num : nums){
            if(num > 0){
                res[pos] = num;
                pos = pos + 2;
            }else{
                res[neg] = num;
                neg = neg + 2;
            }
        }
        return res;
    }
};