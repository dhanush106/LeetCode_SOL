// Last updated: 7/6/2026, 12:00:17 PM
// class FenwickTree {
//     vector<int> bit;
//     int n;

// public:
//     FenwickTree(int size) {
//         n = size;
//         bit.assign(n + 1, 0);
//     }

//     void update(int idx, int val) {
//         while (idx <= n) {
//             bit[idx] += val;
//             idx += idx & (-idx);
//         }
//     }

//     int query(int idx) {
//         int sum = 0;
//         while (idx > 0) {
//             sum += bit[idx];
//             idx -= idx & (-idx);
//         }
//         return sum;
//     }
// };

// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();

//         // Step 1: Build prefix sums after converting
//         // target -> +1
//         // others -> -1
//         vector<int> prefix(n + 1, 0);

//         for (int i = 0; i < n; i++) {
//             if (nums[i] == target)
//                 prefix[i + 1] = prefix[i] + 1;
//             else
//                 prefix[i + 1] = prefix[i] - 1;
//         }

//         // Step 2: Coordinate Compression
//         vector<int> values = prefix;
//         sort(values.begin(), values.end());
//         values.erase(unique(values.begin(), values.end()), values.end());

//         FenwickTree bit(values.size());

//         long long ans = 0;

//         // Step 3: Count previous prefix sums smaller than current
//         for (int x : prefix) {

//             int idx = lower_bound(values.begin(), values.end(), x) - values.begin() + 1;

//             // Number of previous prefix sums < current prefix sum
//             ans += bit.query(idx - 1);

//             bit.update(idx, 1);
//         }

//         return (int)ans;
//     }
// };

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Convert array and build prefix sums
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        // Step 2: Coordinate Compression
        vector<int> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        FenwickTree bit(values.size());

        long long ans = 0;

        // Step 3: Count previous prefix sums smaller than current
        for (int x : prefix) {
            int idx = lower_bound(values.begin(), values.end(), x) - values.begin() + 1;

            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};