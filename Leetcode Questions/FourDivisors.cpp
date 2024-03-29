class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0, temp = 0;

            int square_root = (int)sqrt(nums[i]) + 1;
            for (int j = 1; j < square_root; j++)
            {

                if (nums[i] % j == 0 && j * j != nums[i])
                {
                    temp += j;
                    temp += nums[i] / j;
                    count += 2;
                }

                if (nums[i] % j == 0 && j * j == nums[i])
                {
                    temp += j;
                    count++;
                }
            }
            if (count == 4)
            {
                ans += temp;
            }
        }
        return ans;
    }
};

// This is a correct solution but it is taking more time than allow hence TLE
class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = 0, count = 0;
            for (int j = 1; j <= nums[i]; j++)
            {
                if (nums[i] % j == 0)
                {
                    temp += j;
                    count++;
                }
            }
            if (count == 4)
            {
                ans += temp;
            }
        }
        return ans;
    }
};