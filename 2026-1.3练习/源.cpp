class Solution
{
	vector<int> origin;
public:
	Solution(vector<int>& nums) :origin(std::move(nums))
	{

	}
	vector<int> reset()
	{
		return origin;
	}
	vector<int> shuffle()
	{
		if (origin.empty()) return {};
		vector<int> shuffle(origin);
		int n = origin.size();
		for (int i = 0; i < n; i++)
		{
			swap(shuffle[i], shuffle[rand() % (n - i) + i]);
		}
		return shuffle;
	}
};

