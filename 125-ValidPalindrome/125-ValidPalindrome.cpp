// Last updated: 7/6/2026, 12:02:46 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(char c : s){
            if(isalnum(c)){
                s1 += tolower(c);
            }
        }
        int l = s1.length();
        for(int i = 0; i < l / 2; i++){
            if(s1[i] != s1[l - 1 - i]){
                return false;
            }
        }
        return true;
    }
};
