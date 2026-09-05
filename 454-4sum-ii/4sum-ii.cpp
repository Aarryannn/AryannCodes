class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> mpp;
        for(int i : nums1){
            for(int j : nums2){
                int sum = i+j;
                mpp[sum]++;
            }
        }


        int count = 0;
         for(int i : nums3){
            for(int j : nums4){
                int sum = i+j;
               if(mpp.count(-1*sum)) count += mpp[-1*sum];
            }
        }
        return count;

    }
};