class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> arr = grid;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                arr[i][j] = (arr[i][j] + arr[i][j - 1]);

        int sum = 0, mx = 0;
        for (int i = 2; i < n; i++)
        {
            for (int j = 2; j < m; j++)
            {
                if (j != 2)
                    sum = (arr[i][j] - arr[i][j - 3]) + (arr[i - 2][j] - arr[i - 2][j - 3]) + grid[i - 1][j - 1];
                else
                    sum = (arr[i][j]) + (arr[i - 2][j]) + grid[i - 1][j - 1];
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};