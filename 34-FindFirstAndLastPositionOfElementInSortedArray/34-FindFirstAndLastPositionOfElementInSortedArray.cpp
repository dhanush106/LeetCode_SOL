// Last updated: 7/6/2026, 12:03:40 PM
class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int low=0,high=nums.size()-1,ans=nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high=mid-1;
            }else{
                 low=mid+1;
            }
        }
        cout<<ans<<"--Lower Bound"<<endl;
        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int low=0,high=nums.size()-1,ans=nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                ans = mid;
                high=mid-1;
            }else{
                 low=mid+1;
            }
        }
        cout<<ans<<"--Upper Bound"<<endl;
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,target);
        if(lb == nums.size() || nums[lb] != target){
            return {-1, -1};
        }
        return {lb, upperBound(nums,target)-1};
    }
};