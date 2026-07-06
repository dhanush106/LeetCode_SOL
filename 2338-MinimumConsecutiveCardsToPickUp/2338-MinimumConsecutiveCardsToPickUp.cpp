// Last updated: 7/6/2026, 12:00:28 PM
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last;
        int ans = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (last.find(cards[i]) != last.end()) {
                ans = min(ans, i - last[cards[i]] + 1);
            }
            last[cards[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};