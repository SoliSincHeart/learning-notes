int maxProfit(int k, vector<int>& prices)
{
	int days = prices.size();
	if (days < 2)
	{
		return 0;
	}
	if (k >= days)
	{
		return maxProfitUnlimited(prices);
	}
	vector<int> buy(k + 1, INT_MIN),sell(k + 1, 0);
	for (int i = 0; i < days; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			buy[j] = max(buy[j], sell[j - 1] - prices[i]);//buy[j]表示在第j次买入时的最大收益
			sell[j] = max(sell[j], buy[j]+prices[i]);//sell[j]表示在第j次卖出时的最大收益
		}
	}
	return sell[k];
}


int maxProfitUnlimited(vector<int> prices)
{
	int n = prices.size();
	int max_profit = 0;
	for (int i = 1; i < n; i++)
	{
		if (prices[i] > prices[i - 1])
		{
			max_profit += prices[i] - prices[i - 1];
		}
	}
	return max_profit;
}