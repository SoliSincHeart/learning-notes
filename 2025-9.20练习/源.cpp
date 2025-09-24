class Solution {
public:
    string minWindow(string s, string t)
    {
        vector<int> count(128, 0);
        vector<bool> flag(128, false);

        for (int i = 0; i < t.size(); ++i)
        {
            ++count[t[i]];
            flag[t[i]] = true;
        }

        int ret = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (flag[s[i]])
            {
                if (--count[s[i]] >= 0)
                {
                    ++ret;
                }

                while (ret == t.size())
                {
                    if (i - l + 1 < min_size)
                    {
                        min_l = l;
                        min_size = i - l + 1;
                    }
                    if (flag[s[l]] && ++count[s[l]] > 0)
                    {
                        --ret;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};