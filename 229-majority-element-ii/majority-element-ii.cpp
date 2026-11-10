class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int e1;
        int e2;
        vector<int> ans;
        for(int i : nums){

            if(count1 == 0 && i != e2){
                count1 = 1;
                e1 = i;
            }else if(count2 == 0 && i != e1){
                count2 = 1;
                e2 = i;
            }else if( e1 == i){
                count1++;
              
            } 
             else if(e2 == i){
           
                count2++;
             }
             else{
                count1--;
                count2--;
             }
        }
        count1 = 0;
        count2 = 0;
        for(int i : nums ){
            if(e1 == i) count1++;
            if(e2 == i) count2++;
        }

        if(count1 > nums.size()/3) ans.push_back(e1);
        if(count2 > nums.size()/3) ans.push_back(e2);
       
       return ans;

    }
};