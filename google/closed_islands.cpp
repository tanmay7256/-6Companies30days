class Solution
{
public:
    int ans;
    int find(vector<vector<int>> &grid, int n, int m, int row, int col)
    {
        if (row >= n || row < 0 || col >= m || col < 0)
        {
            return 0;
        }
        if (grid[row][col] == 1 || grid[row][col] == 2)
            return 1;
        int sum = 1;
        grid[row][col] = 2;
        sum = min(find(grid, n, m, row + 1, col), sum);
        sum = min(find(grid, n, m, row, col + 1), sum);
        sum = min(find(grid, n, m, row - 1, col), sum);
        sum = min(find(grid, n, m, row, col - 1), sum);
        return sum;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int k = find(grid, n, m, i, j);
                    ans += k;
                }
            }
        }
        return ans;
    }
};