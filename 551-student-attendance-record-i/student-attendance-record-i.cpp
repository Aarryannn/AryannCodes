
class Solution {
public:
    bool checkRecord(string s) {
        int absences = 0;
        int consecutiveLates = 0;

        for (char c : s) {
            if (c == 'A') {
                absences++;
                if (absences >= 2) return false;
                consecutiveLates = 0;
            } else if (c == 'L') {
                consecutiveLates++;
                if (consecutiveLates >= 3) return false;
            } else {
                consecutiveLates = 0;
            }
        }

        return true;
    }
};