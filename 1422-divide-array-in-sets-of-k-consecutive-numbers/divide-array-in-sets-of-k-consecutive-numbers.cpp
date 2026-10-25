class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;
        unordered_map<int,int> mpp;
        sort(nums.begin(), nums.end());

        for(int i : nums){
            mpp[i]++;
        }

        for(int i = nums.size()-1; i >= 0; i--){
            if( mpp[nums[i]] != 0) {
                int n = nums[i];
                mpp[n]--;
                for(int j = 1; j < k; j++){
                    if(mpp[n-j] == 0) return false;
                    mpp[n-j]--;
                }
            }
        }
return true;
    }
};