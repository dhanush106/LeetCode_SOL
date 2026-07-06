// Last updated: 7/6/2026, 12:02:51 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int  profit = 0;

        for(int i=1;i<n;i++){
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        } 

        return profit;
    }
};