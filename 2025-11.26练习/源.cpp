int minDistance(string word1, string word2)
{
	int n = word1.length();
	int m = word2.length();
	if (n * m == 0) return n + m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (i == 0)
			{
				dp[i][j] = j;
			}
			else if (j == 0)
			{
				dp[i][j] = i;
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
	}
	return dp[n][m];
}