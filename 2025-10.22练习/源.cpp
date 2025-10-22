class Solution {
public:
    vector<int> dic = { -1,0,1,0,-1 };

    int shortestBridge(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        bool flag = false;
        for (int i = 0; i < m; ++i)
        {
            if (flag == true)
                break;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flag = true;
                    break;
                }
            }
        }

        int x, y;
        int level = 0;
        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                points.pop();
                for (int k = 0; k < 4; ++k)
                {
                    x = r + dic[k];
                    y = c + dic[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }
                        if (grid[x][y] == 1)
                        {
                            return level;
                        }
                        points.push(make_pair(x, y));
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }



    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 2)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            points.push(make_pair(i, j));
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i, j + 1);
        dfs(points, grid, m, n, i, j - 1);
    }
};