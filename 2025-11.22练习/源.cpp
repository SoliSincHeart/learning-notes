#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

// 辅函数
pair<int, int> count(const string& s) {
    int count0 = 0, count1 = 0; // 初始化 count0 和 count1 为 0
    for (const char& c : s) {
        if (c == '1') {
            ++count1;
        }
        else if (c == '0') {
            ++count0;
        }
    }
    return make_pair(count0, count1);
}

// 主函数
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const string& str : strs) {
        pair<int, int> counts = count(str);
        int count0 = counts.first;
        int count1 = counts.second;
        for (int i = m; i >= count0; --i) {
            for (int j = n; j >= count1; --j) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1]);
            }
        }
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"--------------------"<<endl;
    }

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[m][n]; // 在函数末尾返回 dp[m][n] 的值
}

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << "The maximum number of strings that can be formed is: " << findMaxForm(strs, m, n) << endl;
    return 0;
}
