class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans(n);
        int alice = 0, bob = 0;
        for (int i = 0; i < n; i++) {
            if (!rain[i]) {
                ans[i] = "None";
            }
            else if (alice <= bob && i < n - 1 && rain[i + 1]) {
                alice++;
                ans[i] = "Alice";
            }
            else {
                bob++;
                ans[i] = "Bob";
            }
        }
        return ans;
    }
};

