class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return n;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            if (dp.back() < nums[i])
            {
                dp.push_back(nums[i]);
            }
            else
            {
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return dp.size();
    }
};