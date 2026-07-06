// Last updated: 7/6/2026, 12:03:27 PM
class Solution {
public:
    // int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    //     if(i == 0 && j == 0) return grid[i][j];
    //     if(i<0 || j <0) return INT_MAX;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int left = solve(grid,i-1,j,dp);
    //     int right = solve(grid,i,j-1,dp);
    //     return dp[i][j] = grid[i][j] + min(left,right);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int left = INT_MAX, right = INT_MAX;
                    if(i>0){
                        left = dp[i-1][j];
                    }
                    if(j>0){
                        right = dp[i][j-1];
                    }
                    dp[i][j] = grid[i][j] + min(left,right);
                }
            }
        }
        return dp[m-1][n-1];
    }
};