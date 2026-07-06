// Last updated: 7/6/2026, 2:27:19 PM
1class Solution {
2public:
3    int maxConsecutiveAnswers(string answerKey, int k) {
4        int l=0,r=0,n=answerKey.size();
5        int maxlen = 0, maxFreq = 0;
6        map<char,int>mp;
7        // for(char c:amswerKey){
8        //     mp[c]++;
9        // }
10        // maxFreq = (mp['T']>mp['F']) ? mp['T'] : mp['F'];
11        while(r<n){
12            mp[answerKey[r]]++;
13            maxFreq = max(maxFreq, max(mp['T'],mp['F']));
14            while((r-l+1)-maxFreq > k){
15                mp[answerKey[l]]--;
16                l++;
17            }
18            maxlen = max(maxlen, r-l+1);
19            r++;
20        }
21        return maxlen;
22    }
23};