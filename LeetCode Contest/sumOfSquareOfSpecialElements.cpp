class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (n % (i + 1) == 0)
            {
                int s = nums[i] * nums[i];
                ans += s;
            }
        }
        return ans;
    }
};