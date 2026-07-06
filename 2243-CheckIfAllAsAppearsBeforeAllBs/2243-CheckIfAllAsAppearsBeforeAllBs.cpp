// Last updated: 7/6/2026, 12:00:32 PM
class Solution {
public:
    bool checkString(string s) {
        int n = s.size(), count = 0;
        for(int i = 1; i<n; i++){
            if(s[i-1] == 'b' & s[i] == 'a'){
                return false;
            }
        }
        return true;
        // if(count<=1) return true;
        // else return false;
    }
};