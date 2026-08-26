class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map <int, int> mpp;
        int sum = 0;
        int len = 0;
        // mpp[0] = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) sum += -1;
            else{
                sum += 1;
            }

            if(sum == 0){
                len = max ( len , i+1);
            }
            else if (mpp.count(sum)){
                len = max( len, i- mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
            
        }
        return len;
    }
};