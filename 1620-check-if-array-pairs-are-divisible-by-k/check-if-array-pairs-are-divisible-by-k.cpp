class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        vector<int> rem(k,0);
        //create a list of freq, how many times each rem came;
        for(int n : nums){
            int r = ((n % k) + k) % k;
            rem[r]++;
        }

        // 0 must be paired with another zero
        if(rem[0] % 2 != 0) return false;


// for each reminder i , their mush exist a k-i so we can pair it
        for(int i = 1; i < k; i++){
            if(rem[i] != rem[k-i]) return false;
        }


        return true;
    }
};