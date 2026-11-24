class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (i == n - 1 || x != nums[i + 1]) { // i 是连续相同段的末尾
                if (i > 0 && start < n - 1) { // 这一段不能只有 nums[0] 或者只有 nums[n-1]
                    ans = min(ans, 1LL * (start + n - i - 1) * x);
                }
                start = i + 1; // 下一段的开始位置
            }
        }
        return ans;
    }
};
