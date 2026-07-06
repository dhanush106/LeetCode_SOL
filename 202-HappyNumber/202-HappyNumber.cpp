// Last updated: 7/6/2026, 12:02:22 PM
class Solution {
public:
    int sqSum(int n){
        int sum = 0;
        while(n>0){
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        vector<int> arr;
        while(find(arr.begin(),arr.end(),sqSum(n)) == arr.end()){
            int temp = sqSum(n);
            n = temp;
            if(temp == 1){
                return true;
                break;
            }
            arr.push_back(temp);
        }
        return false;
    }
};