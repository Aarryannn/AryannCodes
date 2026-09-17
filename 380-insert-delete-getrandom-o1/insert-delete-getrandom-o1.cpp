class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mpp; // mpp[val] = vector_index

public:
    RandomizedSet() {
        // Optional: Seed the random number generator if needed
    }
    
    bool insert(int val) {
        if (mpp.count(val)) {
            return false;
        }
        // Correct 0-based indexing
        mpp[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!mpp.count(val)) {
            return false;
        }
        
        int idx = mpp[val];
        int last = nums.back();
        
        // Move the last element to the place of the element to delete
        nums[idx] = last;
        mpp[last] = idx; // Updates map correctly
        
        // Remove the last element from both data structures
        nums.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        // Correct C++ rand() usage
        return nums[rand() % nums.size()];
    }
};
