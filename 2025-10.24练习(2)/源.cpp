class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2) return 0;
        int a = 0, b = 0, money = 0;
        if(n == 1) return nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            money = max(a + nums[i], b);
            a = b;
            b = money;
        }
        return money;
    }
};