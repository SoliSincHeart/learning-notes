class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        unordered_map<int, int> hash;
        int ans = 0;
        for (const string& word : words)
        {
            int mask = 0, size = word.size();
            for (const char& ch : word)
                mask |= 1 << (ch - 'a');
            hash[mask] = max(hash[mask], size);
            for (const auto& [h_mask, h_len] : hash)
            {
                if ((mask & h_mask) == 0)
                    ans = max(ans, size * h_len);
            }
        }
        return ans;
    }
};