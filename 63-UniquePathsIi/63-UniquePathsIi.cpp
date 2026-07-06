// Last updated: 7/6/2026, 12:03:29 PM
class Solution {
public:
    // int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){

    //     if(i==0&&j==0) return 1;
    //     if(i<0 || j<0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = solve(obstacleGrid, i-1,j,dp);
    //     int left = solve(obstacleGrid, i, j-1,dp);

    //     return dp[i][j] = up+left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
       
       vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0&& obstacleGrid[i][j] == 0) curr[j] = 1;
               else if(obstacleGrid[i][j] == 1) curr[j] = 0;

                else
                {
                int up =0,left=0;
                if(i>0)
                {
                    up = prev[j];
                }
                if(j>0) 
                {
                    left = curr[j-1];
                }

                curr[j] = up+left; 
                }               
            }
            prev = curr;
        }

        return prev[n-1];
    }
};