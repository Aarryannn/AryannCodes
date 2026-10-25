class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int g) {
        if(nums.size() % g != 0) return false;

        sort(nums.begin(), nums.end());
        unordered_map<int,int> mpp;
        for(int i : nums) mpp[i]++;

        for(int i = 0; i < nums.size(); i++){
            if(mpp[nums[i]] != 0){
                int n = nums[i];
                mpp[n]--;
                for(int j = 1; j < g; j++){
                    if(mpp[n+j] == 0) return false;
                    mpp[n+j]--;
                }
            }
        }


        
        return true;
    }
};