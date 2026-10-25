class Solution {
public:
    int atMost(vector<int>& nums, int k){
        if(k == -1) return 0;
        int count = 0;

        int l = 0;
        int r = 0;
        long long sum = 0;
        while(r < nums.size()){
            sum += nums[r];

            while(sum > k){
                sum -= nums[l];
                l++;
            }
            if(sum <= k) count += r-l+1;
            r++;
        }
        return count;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
        
    }
};