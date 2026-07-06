// Last updated: 7/6/2026, 12:00:58 PM
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build LCS DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Reconstruct LCS
        string lcs = "";

        int i = n;
        int j = m;

        while(i > 0 && j > 0){

            if(str1[i-1] == str2[j-1]){
                lcs += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());

        // Your merge logic
        string ans = "";

        i = 0;
        j = 0;

        for(char ch : lcs){

            while(str1[i] != ch)
                ans += str1[i++];

            while(str2[j] != ch)
                ans += str2[j++];

            ans += ch;
            i++;
            j++;
        }

        while(i < n)
            ans += str1[i++];

        while(j < m)
            ans += str2[j++];

        return ans;
    }
};