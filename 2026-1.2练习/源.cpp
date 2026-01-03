class Solution {
    vector<int> sums;
public:
    Solution(vector<int> weights) : sums(std::move(weights)) {
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }
    int pickIndex() {
        int pos = (rand() % sums.back()) + 1;
        return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }
};