class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long ans = 0;
        int mn = INT_MAX, c = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                mn = min(mn, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    c++;
            }
        }
        if (c % 2)
            return ans - 2 * mn;
        return ans;
    }
};