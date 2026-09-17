class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        unordered_map <int, int> mpp;
        for(int i : nums){
            int num = i % k;
            if (num < 0) num += k;
            mpp[num]++;
        }

        if(mpp[0]%2 != 0) return false;

        for(int i = 1; i < k; i++){
            if(mpp[i] != mpp[k-i]) return false;
        }


        return true;
    }
};