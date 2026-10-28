class Solution {
public:
    int numRescueBoats(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size()-1;
        int count = 0;

        while(l <= r){
            if(l==r){
                count++;
                r--;
            }
            else if(nums[l] + nums[r] <= k){
                l++;
                r--;
                count++;
            }else{
                r--;
                count++;
            }
        }
        return count;
    }
};