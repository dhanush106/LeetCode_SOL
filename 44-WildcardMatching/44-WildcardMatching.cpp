// Last updated: 7/6/2026, 12:03:37 PM
class Solution {
public:
    // bool solve(string &s, string &p, int i, int j) {

    //     // Both string and pattern are exhausted
    //     if (i < 0 && j < 0)
    //         return true;

    //     // Pattern exhausted but string remains
    //     if (j < 0)
    //         return false;

    //     // String exhausted
    //     if (i < 0) {
    //         while (j >= 0) {
    //             if (p[j] != '*')
    //                 return false;
    //             j--;
    //         }
    //         return true;
    //     }

    //     // Characters match or '?'
    //     if (s[i] == p[j] || p[j] == '?')
    //         return solve(s, p, i - 1, j - 1);

    //     // '*'
    //     if (p[j] == '*') {
    //         // Match zero characters OR one/more characters
    //         return solve(s, p, i, j - 1) ||
    //                solve(s, p, i - 1, j);
    //     }

    //     return false;
    // }

    bool isMatch(string s, string p) {
        int n1 = s.size(); 
        int n2 = p.size();
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1, false));
        
        dp[0][0] = true;

        for (int j = 1; j <= n2; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if (p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];        
                }else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[n1][n2];
    }
};