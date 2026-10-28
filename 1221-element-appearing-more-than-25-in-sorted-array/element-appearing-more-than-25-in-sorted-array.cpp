class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        int k = nums.size()/4;
        int num = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num){
                count++;
                if(count > k) return num;
            }else{
                num = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};