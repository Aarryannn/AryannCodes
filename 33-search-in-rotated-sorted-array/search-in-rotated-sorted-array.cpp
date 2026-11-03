class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0; int r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;

            if(nums[m] == t) return m;

            // if array is normal
            if(nums[m] >= nums[l]){
                // now check if target lies left or right to the mid
                if(t >= nums[l] && t < nums[m]) r = m-1;
                else l = m+1;
            }else  // rotated array
            {
                // now check if target lies left or right to the mid
                if(nums[m] < t && t <= nums[r]) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};