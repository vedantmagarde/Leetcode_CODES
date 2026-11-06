class Solution
{
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row;
    int col;
    vector<vector<int>> h;

    vector<vector<bool>> bfs(queue<pair<int, int>> &q)
    {
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;
            for (int d = 0; d < 4; d++)
            {
                int newrow = i + dir[d][0];
                int newcol = j + dir[d][1];
                if (newrow < 0 || newcol < 0 || newrow >= row || newcol >= col)
                {
                    continue; // bahar nikal gaya
                }
                if (visited[newrow][newcol] == true)
                    continue;
                if (h[newrow][newcol] < h[i][j])
                    // neighbour< current cell height
                    continue;
                q.push({newrow, newcol});
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        h = heights;
        row = heights.size();
        col = heights[0].size();
        queue<pair<int, int>> pacific_bfs;
        queue<pair<int, int>> atlantic_bfs;
        for (int i = 0; i < row; i++)
        {
            pacific_bfs.push({i, 0});
            atlantic_bfs.push({i, col - 1});
        }
        for (int j = 1; j < col; j++)
        {
            pacific_bfs.push({0, j});
        }
        for (int j = 0; j < col - 1; j++)
        {
            atlantic_bfs.push({row - 1, j});
        }
        vector<vector<bool>> vis_pac = bfs(pacific_bfs);
        vector<vector<bool>> vis_atl = bfs(atlantic_bfs);
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (vis_pac[i][j] && vis_atl[i][j])
                {
                    vector<int> temp = {i, j};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};