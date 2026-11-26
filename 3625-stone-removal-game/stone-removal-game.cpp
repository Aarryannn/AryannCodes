class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        if(n < stones) return false;
        int count = 0;
        while(n >= 0){
            count++;
            if(n < stones) break;
            n -= stones;
            stones--;
        }

        if(count % 2 == 0) return true;
        return false; 
    }
};