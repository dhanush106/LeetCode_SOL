// Last updated: 7/6/2026, 12:00:49 PM
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2*n);
        for(int i=0;i<n;i++){
            res[i*2] = nums[i];
            res[(2*(i%n)+1)] = nums[i+n];
        }
        // for(int i=n;i<2*n;i++){
        // }
        return res;
    }
};