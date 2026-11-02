class Solution {
public:
    int search(vector<int>& nums, int t) {
         int l = 0;
         int r = nums.size()-1;

         while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == t) return mid;
            else if(nums[mid] < t) l = mid+1;
            else r = mid-1;
         }

         return -1;
    }
};