class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int bb = 2e9;
        int profit = 0;
        int b; int s;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] < bb) bb = nums[i];
            profit = max(nums[i]-bb , profit);
        }
        return profit;
    }
};