class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> pos;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(pos.count(val)){
            return false;
        }

        pos[val]= nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
         if(!pos.count(val)){
            return false;
        }

        int idx = pos[val];
        int last = nums.back();

        nums[idx] = last;
        pos[last] = idx;

        nums.pop_back();
        pos.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */