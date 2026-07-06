// Last updated: 7/6/2026, 12:01:04 PM
class Solution {
public:
    // int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&
    // dp){
    //     if(j<0 || j>=matrix.size()) return 1e9;
    //     if(i == matrix.size()-1) return matrix[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = solve(matrix, i+1, j, dp);
    //     int leftdiag = solve(matrix, i+1, j-1,dp);
    //     int rightdiag = solve(matrix, i+1, j+1, dp);

    //     return dp[i][j] = matrix[i][j] + min({down, leftdiag, rightdiag});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(n,0);
            for (int j = n - 1; j >= 0; j--) {
                if (i == n - 1) {
                    curr[j] = matrix[i][j];
                    continue;
                }
                int down = prev[j];
                int leftdiag = 1e9;
                int rightdiag = 1e9;

                if (j > 0)
                    leftdiag = prev[j - 1];

                if (j < n - 1)
                    rightdiag = prev[j + 1];

                curr[j] = matrix[i][j] + min({down, leftdiag, rightdiag});
            }
            prev =  curr;
        }
        int ans = 1e9;
        for(int j = 0; j < n; j++)
            ans = min(ans, prev[j]);

        return ans;
    }
};