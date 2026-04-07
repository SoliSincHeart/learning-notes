vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> hash;
	vector<int> res;
	for (int i = 0; i < nums.size();++i)
	{
		int num = nums[i];
		if (hash.find(target - num) == hash.end())
		{
			hash[num] = i;
		}
		else
		{
			res.push_back(hash[target - num]);
			res.push_back(i);
			break;
		}

	}
	return res;
}