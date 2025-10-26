#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<int> dp(n, 0);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 && j == 0)
			{
				dp[j] = grid[i][j];
			}
			else if (i == 0)
			{
				dp[j] = dp[j-1] + grid[i][j];
			}
			else if (j == 0)
			{
				dp[j] = dp[j] + grid[i][j];
			}
			else
			{
				dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}
	cout<<endl;
	return dp[n-1];
}

int main()
{
	vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	cout << minPathSum(grid) << endl;
	return 0;
}