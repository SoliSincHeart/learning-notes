class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> indices;
        for (int i = 0; i < n; ++i)
        {
            while (!indices.empty())
            {
                int p = indices.top();
                if (temperatures[i] <= temperatures[p])
                {
                    break;
                }
                indices.pop();
                ans[p] = i - p;
            }
            indices.push(i);
        }
        return ans;
    }
};