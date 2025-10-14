vector<int> direction{ -1, 0, 1, 0,-1 };
//int maxAreaOfIsland(vector<vector<int>>& grid)
//{
//	int m = grid.size(), n = m ? grid[0].size() : 0, area = 0, areaConut = 0, x, y;
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if (grad[i][j])
//			{
//				areaConut = 1;
//				grad[i][j] = 0;
//				stack<pair<int, int>> island;
//				island.push({ i,j });
//				while (!island.empty())
//				{
//					auto [r,c] = island.top();
//					island.pop();
//					for (int k = 0; k < 4; ++k)
//					{
//						x = r +direction[k],y = c + dicrection[k+1];
//						if (x >= 0 && x < m && y >= 0 && y < n && grad[x][y] == 1)
//						{
//							grad[x][y] = 0;
//							island.push({ x,y });
//							++areaConut;
//						}
//					}
//				}
//			}
//			area = max(area, areaConut);
//		}
//	}
//	return area;
//}

class Solution {
public:
    vector<int> direction{ -1, 0, 1, 0,-1 };
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int k = 0; k < 4; ++k)
        {
            x = r + direction[k], y = c + direction[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
            {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};

