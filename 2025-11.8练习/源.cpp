#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int> weights, vector<int> values, int N, int W) {
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= N; ++i) {
		int w = weights[i - 1], v = values[i - 1];
		for (int j = 1; j <= W; ++j) {
			if (j >= w) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return dp[N][W];
}

int main()
{
	vector<int> weights = { 1, 3, 4, 5 };
	vector<int> values = { 1, 4, 5, 7 };
	int N = 4, W = 7;
	cout << knapsack(weights, values, N, W) << endl;
	return 0;
}