class Solution {
public:
    int minRange(int a, int b, int c) {
        int nums[3] = { a, b, c };
        ranges::sort(nums);
        return min(nums[2] - nums[0], nums[1]);
    }
};

