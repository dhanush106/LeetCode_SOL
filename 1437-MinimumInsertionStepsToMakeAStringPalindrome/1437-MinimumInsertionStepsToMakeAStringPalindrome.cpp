// Last updated: 7/6/2026, 12:00:52 PM
class Solution {
public:
    int minInsertions(string s) {
        string first = s;
        int n = s.size();
        reverse(s.begin(), s.end());
        string second = s;

        // vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        vector<int> prev(n+1,0);

        for(int i=1;i<=n;i++){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(first[i-1] == second[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }

        return abs(prev[n] - n);
    }
};