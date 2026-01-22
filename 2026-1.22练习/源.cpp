class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
        {
            sum ^= num;
        }
        int diff = (sum == INT_MIN ? sum : sum & (-sum));
        int test1 = 0, test2 = 0;
        for (int num : nums)
        {
            if ((num & diff) == 0)
            {
                test1 ^= num;
            }
            else
            {
                test2 ^= num;
            }
        }
        return { test1, test2 };
    }
};