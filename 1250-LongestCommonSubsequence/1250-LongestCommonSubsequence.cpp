// Last updated: 7/6/2026, 12:00:57 PM
class Solution {
public:
    // int solve(string text1, int ind1, string text2, int ind2,vector<vector<int>>& dp){
    //     if(ind1<0 || ind2<0) return 0;
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     if(text1[ind1] == text2[ind2]){
    //         return dp[ind1][ind2] = 1 + solve(text1,ind1-1,text2,ind2-1,dp);
    //     }
        
    //     return dp[ind1][ind2] = max(solve(text1,ind1-1,text2,ind2,dp), solve(text1,ind1,text2,ind2-1,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        // vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));
        
        vector<int> prev(s2+1,0);
        for(int i=1;i<=s1;i++){
            vector<int> curr(s2+1,0);
            for(int j=1;j<=s2;j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[s2];
    }
};