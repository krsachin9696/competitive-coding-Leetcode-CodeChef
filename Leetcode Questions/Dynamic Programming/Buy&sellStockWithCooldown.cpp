class Solution
{
public:
    int stocks(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {

        if (ind >= prices.size())
        {
            return 0;
        }
        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }

        if (buy == 1)
        {
            return dp[ind][buy] = max((-prices[ind] + stocks(ind + 1, 0, prices, dp)), stocks(ind + 1, 1, prices, dp));
        }

        return dp[ind][buy] = max(prices[ind] + stocks(ind + 2, 1, prices, dp), stocks(ind + 1, 0, prices, dp));
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return stocks(0, 1, prices, dp);
    }
};