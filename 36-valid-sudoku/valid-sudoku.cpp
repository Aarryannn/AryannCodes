class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int row[9][9];
        int col[9][9];
        int box[9][9];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == '.') continue;

                int val = board[i][j] - '0'-1;
                int idx = (i/3)*3 + (j/3);

                if(row[i][val] == 1 || col[j][val] == 1 || box[idx][val] == 1 ) return false;

                row[i][val] = 1;
                col[j][val] = 1;
                box[idx][val] = 1;
            }
        }
        return true;
    }
};