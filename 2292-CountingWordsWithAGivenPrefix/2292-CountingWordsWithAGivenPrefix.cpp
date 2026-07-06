// Last updated: 7/6/2026, 12:00:29 PM
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = pref.size();

        for(string s : words) {

            if(s.size() < n)
                continue;

            bool isThere = true;

            for(int i = 0; i < n; i++) {
                if(s[i] != pref[i]) {
                    isThere = false;
                    break;
                }
            }

            if(isThere)
                ans++;
        }

        return ans;
    }
};