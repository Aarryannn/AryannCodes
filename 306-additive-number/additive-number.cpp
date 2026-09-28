class Solution {
public:
    string add(string a, string b) {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res.push_back('0' + sum % 10);
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(string& s, int pos, string a, string b, int count) {
        if (pos == s.size())
            return count >= 3;

        string sum = add(a, b);

        if (pos + sum.size() > s.size())
            return false;

        if (s.substr(pos, sum.size()) != sum)
            return false;

        return dfs(s, pos + sum.size(), b, sum, count + 1);
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n - 2; i++) {
            if (num[0] == '0' && i > 1)
                break;

            string a = num.substr(0, i);

            for (int j = i + 1; j <= n - 1; j++) {
                if (num[i] == '0' && j - i > 1)
                    break;

                string b = num.substr(i, j - i);

                if (dfs(num, j, a, b, 2))
                    return true;
            }
        }

        return false;
    }
};