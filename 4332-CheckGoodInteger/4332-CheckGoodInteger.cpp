// Last updated: 7/6/2026, 12:00:13 PM
class Solution {
public:
    int digitSum(int n){
        int t = n;
        int sum = 0;
        while(n>0){
            sum = sum + (n%10);
            n = n / 10;
        }
        return sum;
    }

    int squareSum(int n){
        int sum = 0;
        while(n>0){
            sum = sum + ((n%10)*(n%10));
            n = n / 10;
        }
        return sum;
    }
    bool checkGoodInteger(int n) {
        if(squareSum(n) - digitSum(n) >= 50){
            return true;
        }
        return false;
    }
};