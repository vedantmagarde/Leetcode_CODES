class Solution {
public:
    void fun(vector<vector<char>>& board, vector<unordered_set<int>>& row,
             vector<unordered_set<int>>& col,
             vector<vector<unordered_set<int>>>& grid, int r, int c,
             bool& solved) {
        if (solved)
            return;

        for (int i = r; i < 9; i++) {
            for (int j = c; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int digit = 1; digit <= 9; digit++) {
                        char ch = digit + '0';
                        if (row[i].find(ch) == row[i].end() &&
                            col[j].find(ch) == col[j].end() &&
                            grid[i / 3][j / 3].find(ch) ==
                                grid[i / 3][j / 3].end()) {

                            board[i][j] = ch;
                            row[i].insert(ch);
                            col[j].insert(ch);
                            grid[i / 3][j / 3].insert(ch);

                            fun(board, row, col, grid, i, j,solved);

                            if (solved)
                                return;

                            row[i].erase(ch);
                            col[j].erase(ch);
                            grid[i / 3][j / 3].erase(ch);
                            board[i][j] = '.';
                        }
                    }
                    return;
                }
            }
            c = 0;
        }
        solved = true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> col(9);
        vector<vector<unordered_set<int>>> grid(3,
                                                vector<unordered_set<int>>(3));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    grid[i / 3][j / 3].insert(board[i][j]);
                }
            }
        }

        bool solved = false;
        fun(board, row, col, grid, 0, 0, solved);
    }
};