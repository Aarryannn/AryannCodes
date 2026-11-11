class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st;
        unordered_map<int,int> mpp;
        for(int i = nums2.size() -1; i >= 0; i--){
            while(st.size() != 0 && nums2[i] >= st.top()) st.pop();
            if(st.size() == 0){
                mpp[ nums2[i] ] = -1;
            }else{
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i : nums1){
            ans.push_back(mpp[i]);
        }
return ans;
    }
};