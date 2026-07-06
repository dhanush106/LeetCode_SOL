// Last updated: 7/6/2026, 12:00:44 PM
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int n = inventory.size();

        sort(inventory.rbegin(), inventory.rend()); // Sort in descending order
        inventory.push_back(0); // Sentinel value

        for (int i = 0; i < n; ++i) {
            long long current = inventory[i];
            long long next = inventory[i + 1];
            long long count = i + 1; // Number of piles at this level
            long long diff = current - next;
            long long total = diff * count;

            if (orders >= total) {
                // Sell full level down to next
                result += count * (current + next + 1) * diff / 2;
                orders -= total;
            } else {
                // Only sell part of this level
                long long full = orders / count;
                long long rem = orders % count;
                long long high = current;
                long long low = current - full;
                result += count * (high + low + 1) * full / 2;
                result += rem * (low);
                orders = 0;
                break;
            }

            result %= MOD;
            if (orders == 0) break;
        }

        return result % MOD;
    }
};
