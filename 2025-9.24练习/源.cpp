class Solution {
public:
    bool find(string s, string t)
    {
        int n = s.size(), m = t.size();

        if (n < m) return false;
        int i = 0;
        for (char ch : t)
        {
            while (i < n && s[i] != ch) ++i;
            if (i >= n) return false;
            ++i;
        }
        return true;
    }




    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [&](string& a, string& b) {
            if (a.size() == b.size())   return a < b;
            return a.size() > b.size();
            });


        for (string& t : dictionary)
        {
            if (find(s, t)) return t;
        }

        return "";
    }
};