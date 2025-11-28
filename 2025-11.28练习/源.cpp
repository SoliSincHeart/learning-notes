int maxProfit(vector<int>& prices)
{
	int sell = 0;
	int buy = INT_MIN;
	for (int i = 0; i < private.size(); ++i)
	{
		buy = max(buy, -prices[i]);
		sell = max(sell, buy + prices[i]);
	}
	return sell;
}
