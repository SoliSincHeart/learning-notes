class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = -1, right = nums.size() / 2;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (nums[mid * 2] != nums[mid * 2 + 1] ? right : left) = mid;
        }
        return nums[right * 2];
    }
};
