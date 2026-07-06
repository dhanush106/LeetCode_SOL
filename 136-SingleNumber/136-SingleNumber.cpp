// Last updated: 7/6/2026, 12:02:45 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum = sum ^ i;
        }
        return sum;
    }
};