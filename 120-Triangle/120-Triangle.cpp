// Last updated: 7/6/2026, 12:02:53 PM
class Solution {
public:
    // int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
    //    if(i==triangle.size()-1) return triangle[i][j];
    //     if(j>=triangle.size()) return INT_MAX;
        
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = solve(triangle, i+1, j, dp);
    //     int downdiag = solve(triangle, i+1, j+1, dp);

    //     return dp[i][j] = triangle[i][j] + min(down, downdiag);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // vector<vector<int>> dp(m, vector<int>(m,0));
        vector<int> prev(m,0);
        for(int i = m-1;i>=0;i--){
            vector<int> curr(m,0);
            for(int j = 0; j <= i; j++){
                if(i==m-1) curr[j] = triangle[i][j];
                else{
                    int up = prev[j];
                    int updiag = prev[j+1];
                    curr[j] = triangle[i][j] + min(up,updiag);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};