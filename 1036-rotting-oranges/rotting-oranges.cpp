class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(queue<pair<int, int>>& q) {}
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fo = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    fo++;
                else if (grid[i][j] == 2) // push rotten oranges
                    q.push({i, j});       // for mutli-source bfs
            }
        }

        if(fo==0)return 0;
        // saare src add kar liye jaha se bfs lagana hai
        // q.push({-1, -1}); // use to separate

        int mins = 0;
        while (!q.empty()) {

            int size = q.size();

            while (size--) {
                auto cell = q.front();
                q.pop();
                int i = cell.first;
                int j = cell.second;

                for (int d = 0; d < 4; d++) {
                    int neigh_row = i + dir[d][0];
                    int neigh_col = j + dir[d][1];

                    if (0 <= neigh_row && 0 <= neigh_col && neigh_col < col &&
                        neigh_row < row && grid[neigh_row][neigh_col] == 1) {
                            
                        fo--;
                        grid[neigh_row][neigh_col] = 2;
                        q.push({neigh_row, neigh_col});
                    }
                }
            }
            mins++;
        }
        return (fo == 0) ? mins - 1 : -1;
    }
};