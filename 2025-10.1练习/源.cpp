class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
    int quickSelect(vector<int>& nums, int k) {
        int p = nums[rand() % nums.size()];
        vector<int> big, equal, small;
        for (int a : nums) {
            if (a < p) small.push_back(a);
            else if (a == p) equal.push_back(a);
            else big.push_back(a);
        }
        if (k <= big.size()) {
            return quickSelect(big, k);
        }
        if (big.size() + equal.size() < k) {
            return quickSelect(small, k - (big.size() + equal.size()));
        }
        return p;
    }
};