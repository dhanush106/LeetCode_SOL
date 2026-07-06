// Last updated: 7/6/2026, 12:01:00 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string res = "";
        for(char ch : s){
           if (ch == '('){
                if(count>0){
                    res += ch;
                }
                count++;
           }
           else{
            count--;
                if(count>0){
                    res+=ch;
                }
           }
        }
        return res;
    }
};