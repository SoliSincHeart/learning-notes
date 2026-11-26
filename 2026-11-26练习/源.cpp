class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }

        vector<long long> ans(n, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        requiredSignals[0] = 1;

        while (!pq.empty()) {
            auto [t, x] = pq.top();
            pq.pop();
            requiredSignals[x]--;
            if (requiredSignals[x] != 0) { // x 尚未激活或者已经激活
                continue;
            }
            ans[x] = t;
            for (auto& [y, delay] : g[x]) {
                pq.emplace(t + delay, y);
            }
        }

        return ans;
    }
};
