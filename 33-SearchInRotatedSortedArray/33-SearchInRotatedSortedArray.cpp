// Last updated: 7/6/2026, 12:03:41 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[low] <= nums[mid]){
                if(nums[low]<=target && nums[mid]>target){
                    high = mid - 1;
                }else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<target && nums[high]>=target){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};