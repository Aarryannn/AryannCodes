class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // if(n == 0) return {};
        vector<int> left(n);
        // vector<int> right(n);

        left[0] = 1;
        // right[n-1] = 1;

        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
            // right[n-i-1] = right[n-i] * nums[n-i];
        }
    vector<int> ans(n);
        int r = 1;
        for(int i = n-1; i >= 0 ; i--){
            ans[i] = left[i]  * r;
            r = nums[i]* r;
            
        }

        return ans;


    }
};