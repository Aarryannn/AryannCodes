class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prefix = 1;
        long long sufix = 1;
        int n = nums.size()-1;
        long long maxi = INT_MIN;
        for(int i = 0; i <nums.size();i++){
            if( prefix == 0 ) prefix = 1;
            if( sufix == 0 ) sufix = 1;
            prefix *= nums[i];
            sufix *= nums[n-i];
            maxi = max(maxi, max(sufix, prefix));
        }
       

        return maxi;
    }
};