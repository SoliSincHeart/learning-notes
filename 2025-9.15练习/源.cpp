class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || a[0] == b[0] && a[1] < b[1];
            });

        list<vector<int>> list;
        for (auto& e : people)
        {
            auto pos = list.begin();
            advance(pos, e[1]);
            list.insert(pos, e);
        }
        return std::vector<vector<int>>(list.begin(), list.end());
    }
};