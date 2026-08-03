class Solution {
public:
    int f(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row,
          int col) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (col < 0 || col >= m)
            return INT_MAX;
        if (row == n - 1)
            return matrix[row][col];
        if (dp[row][col] != INT_MAX)
            return dp[row][col];
        int down_left = f(matrix, dp, row + 1, col - 1);
        int down = f(matrix, dp, row + 1, col);
        int down_right = f(matrix, dp, row + 1, col + 1);
        return dp[row][col] =
                   matrix[row][col] + min(down_left, min(down, down_right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n + 5, vector<int>(n + 5, INT_MAX));
        for (int i = 0; i < matrix[0].size(); i++) {
            ans = min(ans, f(matrix, dp, 0, i));
        }
        return ans;
    }
};