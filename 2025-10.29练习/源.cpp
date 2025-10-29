#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}
	int m = matrix.size(), n = matrix[0].size(), max_side = 0;
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (matrix[i - 1][j - 1] == '1') {
				cout<<matrix[i - 1][j - 1]<<endl;
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				cout << dp[i][j] << endl;
				for (int k = 0; k <= m; ++k)
				{
					for (int l = 0; l <= n; ++l)
					{
						cout<<dp[k][l]<<" ";
					}
					cout<<endl;
				}
			}
			max_side = max(max_side, dp[i][j]);
		}
	}
	return max_side * max_side;
}

int main() {

	vector<vector<char>> matrix = { {'0','1','1','0'},
									{'0','1','1','1'},
									{'0','1','1','1'},
									{'0','1','1','1'}
									};


	cout << maximalSquare(matrix) << endl;

	return 0;
}
