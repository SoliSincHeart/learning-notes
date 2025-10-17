vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> num(k,0);
    int count = 0;
    backtracking(res, num, count, 1, k, n);
    return res;
}

void backtracking(vector<vector<int>> &res, vector<int> &num, int count, int pos, int k, int n)
{
    if (count == k)
    {
        res.push_back(num);
        return;
    }
    for (int i = pos; i <= n; ++i)
    {
        num[count++] = i;
        backtracking(res, num, count, i + 1, k, n);
        --count;
    }
}