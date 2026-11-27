
class Solution {
public:
    int integerReplacement(int n) {
        long long x = n;
        int ans = 0;

        while (x != 1) {
            if (x % 2 == 0) {
                x /= 2;
            }
            else if (x == 3 || (x & 3) == 1) {
                x--;
            }
            else {
                x++;
            }

            ans++;
        }

        return ans;
    }
};
