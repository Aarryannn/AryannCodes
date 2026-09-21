#include <vector>
#include <unordered_map>

using namespace std;

class Solution { 
public: 
    vector<vector<int>> groupThePeople(vector<int>& nums) { 
        unordered_map<int, vector<int>> mpp; 
        
        // Step 1: Map each group size to the indices of people who want that size
        for(int i = 0; i < nums.size(); i++){ 
            mpp[nums[i]].push_back(i); 
        } 
        
        vector<vector<int>> ans; 
        
        // Step 2: Divide the people into groups of their required sizes
        for(auto it : mpp){ 
            int size = it.first; 
            vector<int>& people = it.second; // Fixed: Removed ()
            
            for(int i = 0; i < people.size(); i += size){ 
                vector<int> grp; // Fixed: Changed type from vector<vector<int>> to vector<int>
                
                for(int j = i; j < i + size; j++){ // Fixed: Removed () from size
                    grp.push_back(people[j]); 
                } 
                ans.push_back(grp); 
            } 
        } 
        return ans; // Fixed: Now correctly placed inside the function scope
    } 
};
