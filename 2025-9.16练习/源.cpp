class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int num = nums.size();
        int res = 0;
        for (int i = 1; i < num; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (i == 1 || nums[i] >= nums[i - 2])
                {
                    nums[i - 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
                ++res;
            }
        }
        return res < 2;
    }
};