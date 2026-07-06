// Last updated: 7/6/2026, 12:00:55 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp1,mp2;
        for(char ch : string("balloon")){
            mp2[ch] = 0;
            mp1[ch] = 0;
        }

        for(char ch : string("balloon")){
            mp1[ch]++;
        }

        for(char ch : text){
            mp2[ch]++;
        }
        int ans = mp2['b']/mp1['b'];
        for(char ch : string("alon")){
            ans = min(ans,mp2[ch]/mp1[ch]);
        }
        return ans;
    }
};