class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        for(int i : arr) mpp[i]++;
        int count = 0;

       int n = 1;
       int i = 0;
        while(count < k){
            if(mpp[n+i] <= 0) count++;
            i++;

        }
        return n+i-1;
    }
};