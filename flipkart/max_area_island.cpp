class Solution
{
public:
    int ans = 0;
    int find(vector<vector<int>> &grid, int n, int m, int row, int col)
    {
        if (row >= n || row < 0 || col >= m || col < 0 || grid[row][col] == 0 || grid[row][col] == 2)
        {
            return 0;
        }
        int sum = 1;
        grid[row][col] = 2;
        sum += find(grid, n, m, row + 1, col);
        sum += find(grid, n, m, row, col + 1);
        sum += find(grid, n, m, row - 1, col);
        sum += find(grid, n, m, row, col - 1);
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int k = find(grid, n, m, i, j);
                    ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};