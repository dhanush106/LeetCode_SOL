// Last updated: 7/6/2026, 12:02:35 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele = 0;
        int count = 0;
        for(int num : nums){
            if(count == 0){
                ele = num;
            }

            if( num == ele){
                count++;
            }else{
                count--;
            }
        }
        return ele;
    }
};