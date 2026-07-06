// Last updated: 7/6/2026, 12:01:58 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> front1(2, 0); // dp[i+1]
        vector<int> front2(2, 0); // dp[i+2]
        vector<int> curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {

            curr[1] = max(
                -prices[i] + front1[0],
                front1[1]
            );

            curr[0] = max(
                prices[i] + front2[1],
                front1[0]
            );

            front2 = front1;
            front1 = curr;
        }

        return front1[1];
    }
};