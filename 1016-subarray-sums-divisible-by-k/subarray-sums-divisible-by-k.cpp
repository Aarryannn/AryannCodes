class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int, int> mpp;
        int sum = 0;
        int count = 0;
        mpp[0]++;
         for(int i : nums){
            sum += i;
            int rem = sum % k;
            if(rem < 0) rem += k;
           
            if(mpp.count(rem))
            {
                count += mpp[rem];
                // mpp[rem]++;
            }
            
          mpp[rem]++;
            
         }
         return count;
    }
};