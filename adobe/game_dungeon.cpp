class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if (n == 1 && m == 1)
        {
            if (dungeon[0][0] >= 0)
                return 1;
            else
                return 1 - dungeon[0][0];
        }
        vector<vector<int>> dp = dungeon;
        if (dp[m - 1][n - 1] >= 0)
            dp[m - 1][n - 1] = 1;
        else
            dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            if ((dp[m - 1][j + 1] - dungeon[m - 1][j]) <= 0)
                dp[m - 1][j] = 1;
            else
                dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
            // cout<<dp[m-1][j]<<" ";
        }
        // cout<<endl;
        for (int i = m - 2; i >= 0; i--)
        {
            if ((dp[i + 1][n - 1] - dungeon[i][n - 1]) <= 0)
                dp[i][n - 1] = 1;
            else
                dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
            // cout<<dp[i][n-1]<<" ";
        }
        // cout<<endl;
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                int a = dp[i + 1][j] - dungeon[i][j];
                if (a <= 0)
                    a = 1;
                int b = dp[i][j + 1] - dungeon[i][j];
                if (b <= 0)
                    b = 1;
                dp[i][j] = min(a, b);
            }
        }
        return dp[0][0];
    }
};