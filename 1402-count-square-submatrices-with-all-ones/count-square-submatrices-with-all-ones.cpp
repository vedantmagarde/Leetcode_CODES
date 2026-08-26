class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        if (r >= matrix.size() || c >= matrix[0].size() || matrix[r][c] == 0)
            return 0;

        if (dp[r][c] != 0)
            return dp[r][c];
        return dp[r][c] = 1 + min({solve(r + 1, c, matrix, dp),
                                   solve(r + 1, c + 1, matrix, dp),
                                   solve(r, c + 1, matrix, dp)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans += solve(i, j, matrix, dp);
            }
        }
        return ans;
    }
};