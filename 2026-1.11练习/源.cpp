class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		sort(nums.begin(), nums.end());
		int sum = 0;
		while (left < right)
		{
			sum += nums[right--] - nums[left++];
		}
		return sum;
	}
};


