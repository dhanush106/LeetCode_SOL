// Last updated: 7/6/2026, 12:00:16 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) prefix[i + 1] = prefix[i] + 1;
            else prefix[i + 1] = prefix[i] - 1;
        }

        int ans = 0;
        multiset<int> s;
        s.insert(0);

        for (int i = 1; i <= n; i++) {
            ans += distance(s.begin(), s.lower_bound(prefix[i]));
            s.insert(prefix[i]);
        }

        return ans;
    }
};