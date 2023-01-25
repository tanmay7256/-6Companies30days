class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> l = grid, r = grid;
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n - 1; j++)
                l[i][j] += l[i - 1][j + 1];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                r[i][j] += r[i - 1][j - 1];
        set<int, greater<int>> s;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                s.insert(grid[i][j]);
                for (int k = 1; k <= min((m - i - 1) / 2, min(n - j - 1, j)); k++)
                    s.insert((l[i + k][j - k] - l[i][j]) + (r[i + k][j + k] - r[i][j]) + (l[i + (2 * k)][j] - l[i + k][j + k]) + (r[i + (2 * k)][j] - r[i + k][j - k]) + grid[i][j] - grid[i + (2 * k)][j]);
            }
        vector<int> ans;
        for (auto &i : s)
            if (ans.size() < 3)
                ans.push_back(i);
            else
                break;
        return ans;
    }
};