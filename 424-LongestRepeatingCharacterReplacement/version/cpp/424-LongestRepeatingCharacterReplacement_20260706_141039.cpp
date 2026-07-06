// Last updated: 7/6/2026, 2:10:39 PM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int l=0,r=0,n=s.size();
5        int maxlen = 0;
6        vector<int> freq(26,0);
7        int maxFreq = 0;
8        for(int r=0;r<n;r++){
9            freq[s[r]-'A']++;
10            maxFreq = max(maxFreq,freq[s[r]-'A']);
11
12            while((r-l+1)-maxFreq > k){
13                freq[s[l]-'A']--;
14                l++;
15            }
16            maxlen = max(maxlen, r-l+1);
17        }
18        return maxlen;
19    }
20};