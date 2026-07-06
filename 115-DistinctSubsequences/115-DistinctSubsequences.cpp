// Last updated: 7/6/2026, 12:02:54 PM
class Solution {
public:
    // int solve(string s, string t, int n1, int n2,vector<vector<int>>& dp){
    //     if(n2<0) return 1;
    //     if(n1<0) return 0;

    //     if(dp[n1][n2] != -1) return dp[n1][n2];

    //     if(s[n1] == t[n2]){
    //         return dp[n1][n2] = solve(s,t,n1-1,n2,dp) + solve(s,t,n1-1,n2-1,dp);
    //     }

    //     return dp[n1][n2] = solve(s,t,n1-1,n2,dp);
    // }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<unsigned long long>> dp(n1+1,vector<unsigned long long>(n2+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n1;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n1][n2];
    }
};