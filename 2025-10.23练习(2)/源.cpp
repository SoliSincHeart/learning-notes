class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<int> num;
        sort(candidates.begin(), candidates.end());
        int start = 0;
        vector<vector<int>> ans;
        backtrack(num, target, candidates, start, ans);
        return ans;

    }
    void backtrack(vector<int>& state, int target, vector<int>& choices, int start, vector<vector<int>>& res)
    {
        if (target == 0)
        {
            res.push_back(state);
            return;
        }
        for (int i = start; i < choices.size(); ++i)
        {
            if (target - choices[i] < 0)
            {
                break;
            }
            if (i > start && choices[i] == choices[i - 1])
            {
                continue;
            }
            state.push_back(choices[i]);
            backtrack(state, target - choices[i], choices, i + 1, res);
            state.pop_back();
        }
    }
};