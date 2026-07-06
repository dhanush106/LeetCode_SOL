// Last updated: 7/6/2026, 2:16:46 PM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums) {
4        int l =0,r=0,zero=0,n=nums.size();
5        int maxlen = 0;
6        while(r<n){
7            if(nums[r] == 0){
8                zero++;
9            }
10            while(zero>1){
11                if(nums[l] == 0){
12                    zero--;
13                }
14                l++;
15            }
16            maxlen = max(maxlen, r-l);
17            r++;
18        }
19        return maxlen;
20    }
21};