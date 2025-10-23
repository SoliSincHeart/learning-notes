class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtracking(nums, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums, int level)
    {
        if (level == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for (int i = level; i < nums.size(); ++i)
        {
            if (st.find(nums[i]) != st.end())
                continue;
            st.insert(nums[i]);
            swap(nums[i], nums[level]);
            backtracking(nums, level + 1);
            swap(nums[i], nums[level]);
        }
    }
};