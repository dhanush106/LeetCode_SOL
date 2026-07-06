// Last updated: 7/6/2026, 12:03:58 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;
        int i = 0;
        int n = nums.size();
        int j =  n-1;
        for(int i = 0; i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        while(i<j){
            if(vec[i].first+vec[j].first == target){
                return {vec[i].second,vec[j].second};
            }else if(vec[i].first+vec[j].first < target){
                i++;
            }else if(vec[i].first+vec[j].first > target){
                j--;
            }
        }
        return {vec[i].second, vec[j].second};
    }
};