#include<iostream>
#include<vector>

using namespace std;
//0-1背包问题
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

	cout<<"dp:"<<endl;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------"<<endl;
	return dp[N][W];
}


//优化空间
int knapsack_opt(vector<int> weights, vector<int> values, int N, int W)
{
	vector<int> dp(W + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int w = weights[i - 1], v = values[i - 1];
		for (int j = W; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout<<"dp:"<<endl;
	for (int i = 0; i <= W; i++)
	{
		cout << dp[i] << " ";
	}
	cout<<endl;
	cout << "-------------------------"<<endl;
	return dp[W];
}

//完全背包问题
int knapsack_complete(vector<int> weights, vector<int> values, int N, int W) {
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= N; ++i) {
		int w = weights[i - 1], v = values[i - 1];
		for (int j = 1; j <= W; ++j) {
			if (j >= w) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w] + v);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << "dp:" << endl;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
	return dp[N][W];
}

//优化空间
int knapsack_complete_opt(vector<int> weights, vector<int> values, int N, int W)
{
	vector<int> dp(W + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int w = weights[i - 1], v = values[i - 1];
		for (int j = w; j<=W; j++)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << "dp:" << endl;
	for (int i = 0; i <= W; i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	cout << "-" << endl;
	return dp[W];
}


int main()
{
	vector<int> weights = { 1, 3, 4, 5 };
	vector<int> values = { 1, 4, 5, 7 };
	int N = 4, W = 7;
	//cout <<"knapsack:"<< knapsack(weights, values, N, W) << endl;
	//cout<<"knapsack_opt:" << knapsack_opt(weights, values, N, W) << endl;
    //cout<<"knapsack_complete:" << knapsack_complete(weights, values, N, W) << endl;
	cout<<"knapsack_complete_opt:" << knapsack_complete_opt(weights, values, N, W) << endl;
	return 0;
}