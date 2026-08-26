class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0;
        mpp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;

            if(mpp.count(rem)){
                if(i - mpp[rem] >= 2){
                    return true;
                }
            }else{

            mpp[rem] = i;;
            }

        }
        return false;
    }
};