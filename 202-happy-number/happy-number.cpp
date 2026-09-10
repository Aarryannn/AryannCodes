class Solution {
private:
    unordered_set <int> s;
public:
    bool isHappy(int n) {
        if(n == 0) return false;
        int sum = 0;
        while(n > 0){
            int digit = n%10;
            sum += digit * digit;
            n = n/10;
        }
        if( sum == 1) return true;
        if(s.find(sum) != s.end()) return false;
        else s.insert(sum);
       ;

        return  isHappy(sum);
    }
};