class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    long long n = nums.size();
        long long Asum= 0;
    
        for(int i : nums) Asum += i;

        long long Tsum = n*(n+1)/2;

        long long TSsum = n*(n+1)*(2*n+1)/6;
        long long ASsum = 0;
        for(long long i : nums) ASsum += i * i;


        long long eq1 = Tsum - Asum;
        long long eq2 = TSsum - ASsum;

        eq2 = eq2/eq1;

        int x = (eq1+eq2)/2;
        int y = x - eq1;


        return {y, x};


    }
};