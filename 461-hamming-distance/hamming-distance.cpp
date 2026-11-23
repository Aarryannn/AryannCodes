
class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        int count = 0;

        while(num) {
            num = num & (num - 1);
            count++;
        }

        return count;
    }
};
