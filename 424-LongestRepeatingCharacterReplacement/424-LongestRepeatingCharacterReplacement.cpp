// Last updated: 7/6/2026, 2:12:05 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size();
        int maxlen = 0;
        vector<int> freq(26,0);
        int maxFreq = 0;
        for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq,freq[s[r]-'A']);

            while((r-l+1)-maxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};