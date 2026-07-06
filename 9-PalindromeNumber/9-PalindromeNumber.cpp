// Last updated: 7/6/2026, 12:03:53 PM
class Solution {
public:
    bool isPalindrome(int x) {
        int orginal=x;
        long reversed=0;
        if(x<0){
            return false;
        }
        while(x>0){
            reversed=(reversed*10)+x%10;
            x=x/10;
        }
        return reversed==orginal;
    }
};