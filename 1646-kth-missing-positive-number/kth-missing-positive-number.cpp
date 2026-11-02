class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0; int r = arr.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;

            if(arr[m] - m > k) r = m -1;
            else l = m+1;
        }

        return r+k+1;
    }
};