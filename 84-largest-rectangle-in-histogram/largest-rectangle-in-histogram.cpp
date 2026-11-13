class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack <long long> st;
        vector<long long> nse(nums.size());
        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >=  nums[i]) st.pop();

            if(st.empty()) nse[i] = nums.size();
            else{
                nse[i] = st.top();
            }

            st.push(i);
        }

        st = {};
        vector<long long> pse(nums.size());
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] >=  nums[i]) st.pop();

            if(st.empty()) pse[i] = -1;
            else{
                pse[i] = st.top();
            }

            st.push(i);
        }

        // now solving question
        long long ans  = 0;
        for(int i = 0; i < nums.size(); i++){
            long long w = nse[i] - pse[i] -1;
            long long area = nums[i] * w;
            ans = max(ans, area);
        }
return ans;


        
    }
};