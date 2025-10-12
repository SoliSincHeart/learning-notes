class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        int x;
        for (int i = 0; i < nums.size(); ++i)
        {
            x = nums[i];
            nums[i] = 2;
            if (x <= 1)
            {
                nums[p1++] = 1;
            }
            if (x == 0)
            {
                nums[p0++] = 0;
            }
        }
    }
};