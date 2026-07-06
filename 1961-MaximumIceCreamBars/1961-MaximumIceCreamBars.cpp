// Last updated: 7/6/2026, 12:00:38 PM
class Solution {
public:
    vector<int> countingSort(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());

        vector<int> count(mx + 1, 0);

        for (int x : arr)
            count[x]++;

        vector<int> ans;

        for (int i = 0; i <= mx; i++) {
            while (count[i]--) {
                ans.push_back(i);
            }
        }

        return ans;
    }
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> costs1 = countingSort(costs);
        int ans = 0;

        for(int i : costs1){
            if(coins>=i){
               ans++;
               coins = coins-i; 
            }
        }
        return ans;
    }
};