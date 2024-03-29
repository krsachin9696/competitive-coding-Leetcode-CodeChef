class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int &cnt)
    {
        vis[row][col] = 1;

        cnt += grid[row][col];
        // cout<<grid[row][col]<<" "<<fish<<endl;

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != 0 && !vis[nrow][ncol])
            {
                dfs(nrow, ncol, grid, vis, cnt);
            }
        }
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int ans = 0;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] != 0)
                {
                    dfs(i, j, grid, vis, cnt);
                    ans = max(ans, cnt);
                    cnt = 0;
                }
            }
        }
        return ans;
    }
};