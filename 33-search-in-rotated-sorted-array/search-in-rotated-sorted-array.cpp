class Solution {
public:
    int search(vector<int>& n, int target) {
        int l=0;
        int r=n.size()-1;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(n[mid]==target){
                return mid;
            }

            if(n[l]<=n[mid]){
                if(n[mid]==target){
                return mid;
            }

                if(target<n[mid] && target >= n[l]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(n[mid]==target){
                return mid;
            }

                if(target>n[mid] && target <= n[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};