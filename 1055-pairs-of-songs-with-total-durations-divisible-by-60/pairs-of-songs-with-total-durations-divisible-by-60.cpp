class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
       int k =  60;
       int count = 0;
        unordered_map<int,int> set;
        for(int i = 0; i < nums.size(); i++){
            int r = ((nums[i]%k)+k) % k;
            if(r == 0){
                if(set.count(0)){
                    count += set[0];
                }
            }
            else if(set.count( k - r)) count += set[k-r];

            set[r]++;
        }
        return count;
    }
};