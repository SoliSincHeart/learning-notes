#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;
    vector<int> dp(n, 0);
    for (int i = 2; i < n; ++i)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout<<endl;
    return accumulate(dp.begin(), dp.end(), 0);
}

int main()
{
    vector<int> nums = { 1, 2, 3, 4 };
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}