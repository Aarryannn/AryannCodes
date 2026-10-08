class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int myDist = abs(target[0]) + abs(target[1]);

        for (auto& ghost : ghosts) {
            int ghostDist = abs(ghost[0] - target[0]) 
                          + abs(ghost[1] - target[1]);

            if (ghostDist <= myDist)
                return false;
        }

        return true;
    }
};