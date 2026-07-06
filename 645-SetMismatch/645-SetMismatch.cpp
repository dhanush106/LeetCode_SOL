// Last updated: 7/6/2026, 12:01:15 PM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int rep,miss;
        long long a = (long long)n*(n+1)/2;
        cout<<"A :: "<<a<<endl;
        long long b = (long long)n*(n+1)*(2*n + 1)/6;
        cout<<"B :: "<<b<<endl;
        long long sum = 0, square_sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            square_sum += nums[i]*nums[i];
        }
        int diff = a - sum;
        int sq_diff = b - square_sum;
        cout<<"DIFF AND SQ_DIFF ::: "<<diff<<" && "<<sq_diff<<endl;

        int temp = sq_diff/diff;
        miss = (temp+diff)/2;
        rep = miss - diff;

        return {rep, miss};

        
    }
};