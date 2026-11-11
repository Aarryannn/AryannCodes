#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int pivot = -1;

        // 1. Find pivot from right to left
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot exists, return -1 (e.g., digits are strictly descending)
        if (pivot == -1) return -1;

        // 2. Find the rightmost element greater than s[pivot]
        int nge = -1;
        for (int i = s.length() - 1; i > pivot; i--) {
            if (s[i] > s[pivot]) {
                nge = i;
                break;
            }
        }

        // 3. Swap pivot and nge
        swap(s[pivot], s[nge]);

        // 4. Reverse the suffix right after the pivot
        reverse(s.begin() + pivot + 1, s.end());

        // 5. Check 32-bit signed integer overflow
        long long ans = stoll(s);
        if (ans > INT_MAX) return -1;

        return (int)ans;
    }
};
