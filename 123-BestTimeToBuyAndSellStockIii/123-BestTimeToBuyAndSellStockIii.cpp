// Last updated: 7/6/2026, 12:02:49 PM

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
             vector<vector<int>> curr(2, vector<int>(3, 0));
            for (int cap = 1; cap <= 2; cap++) {

                // bUy state
                curr[1][cap] = max(
                    -prices[i] + prev[0][cap],
                    prev[1][cap]
                );

                curr[0][cap] = max(
                    prices[i] + prev[1][cap - 1],
                    prev[0][cap]
                );
            }
            prev = curr;
        }

        return prev[1][2];
    }
};