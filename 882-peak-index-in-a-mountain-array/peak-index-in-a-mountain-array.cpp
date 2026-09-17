class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int l = 1;
        int r = nums.size()-2;
        while(l <=  r){
            int mid = (l+r)/2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid] > nums[mid - 1]){        // increasing case;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
};