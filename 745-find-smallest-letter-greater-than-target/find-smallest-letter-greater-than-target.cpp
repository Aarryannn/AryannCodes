class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char target) {
        int l = 0;
        int r = nums.size()-1;
        char ans = nums[0];
        while(l<=r){
            int m = l + (r-l)/2;
                if(nums[m] > target ){
                    ans = nums[m];
                    r = m-1;
                }else{
                    l = m+1;
                }
        }

        return ans;
    
    }
};