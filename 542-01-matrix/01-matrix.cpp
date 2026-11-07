class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> result(r, vector<int>(c, -1));

        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = curr.first + dir[d][0];
                int nc = curr.second + dir[d][1];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c &&
                    result[nr][nc] == -1 && mat[nr][nc] == 1) {
                    result[nr][nc] = result[curr.first][curr.second] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return result;
    }
};