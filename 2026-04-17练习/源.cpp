class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> s_index(265, 0), t_index(265, 0);
        for (int i = 0; i < s.length(); i++)
        {
            if (s_index[s[i]] != t_index[t[i]]) {
                return false;
            }
            s_index[s[i]] = t_index[t[i]] = i + 1;
        }
        return true;
    }
};