class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int bigIdx = -1;
        int bigVal = -2e9;
        vector<int> ans(nums.size());
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] > bigVal){
                bigVal = nums[i];
                bigIdx = i;
            }

            while(st.size() != 0 && nums[i] >= st.top()) st.pop();

            if(st.size() == 0) ans[i] = -1;
            else ans[i] = st.top();
            
            st.push(nums[i]);
        }
        for(int i = nums.size()-1; i >= bigIdx; i--){
            while(st.size() != 0 && nums[i] >= st.top()) st.pop();

            if(st.size() == 0) ans[i] = -1;
            else ans[i] = st.top();
            
            st.push(nums[i]);
        }

        
        return ans;
    }
};