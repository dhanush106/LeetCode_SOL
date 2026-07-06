// Last updated: 7/6/2026, 12:03:55 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int maxlen = 0;
        map<char,int> mp;
        for(char c : s){
            mp[c] = -1;
        }
        int n = s.size();
        while(r<n){
            if(mp[s[r]] != -1){
                if(mp[s[r]]>=l){
                    l = mp[s[r]] + 1;
                }
            }
            int len = r-l+1;
            cout<<len<<endl;
            maxlen = max(maxlen,len);
            mp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};