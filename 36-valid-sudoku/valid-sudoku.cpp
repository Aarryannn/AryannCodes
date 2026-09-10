class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
       
       int row[9][9] = {0};
       int col[9][9] = {0};
       int box[9][9] = {0};

       for(int i = 0 ; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(nums[i][j] == '.') continue;

            int val = nums[i][j] - '1';
            int box_num = (i/3)*3 + (j/3);


            if(row[i][val] == 1 || col[j][val] == 1 || box[box_num][val] == 1) return false;

            row[i][val] = 1;
            col[j][val] = 1;
            box[box_num][val] = 1;

        }
       }

       return true;

    }
};