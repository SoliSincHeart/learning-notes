class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return s;
        int max = 1;
        int start = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;
                max = 2;
            }
        }

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; len + i - 1 < n; ++i)
            {
                int j = len + i - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                    max = len;
                    start = i;
                }
            }
        }
        return s.substr(start, max);
    }
};
