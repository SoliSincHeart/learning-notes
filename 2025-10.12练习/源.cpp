class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (const auto& p : s)
        {
            ++mp[p];
        }
        vector<pair<char, int>> v;
        for (const auto& m : mp)
        {
            v.push_back(m);
        }
        sort(v.begin(), v.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {return p1.second > p2.second; });
        string result;
        for (const auto& k : v)
        {
            result += string(k.second, k.first);
        }
        return result;
    }
};