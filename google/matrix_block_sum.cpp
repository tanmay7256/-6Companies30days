class Solution
{
public:
    int ifexists(int i, int j, int n, int m, vector<vector<int>> &mat)
    {
        if (i < 0 || j < 0)
            return 0;
        if (i >= n)
            i = n - 1;
        if (j >= m)
            j = m - 1;
        return mat[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> arr = mat;
        int n = mat.size(), m = mat[0].size();

        for (int i = 1; i < n; i++)
            mat[i][0] += mat[i - 1][0];

        for (int i = 1; i < m; i++)
            mat[0][i] += mat[0][i - 1];

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
            {
                mat[i][j] += (-mat[i - 1][j - 1] + mat[i - 1][j] + mat[i][j - 1]);
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int a = ifexists(i + k, j + k, n, m, mat);
                int b = ifexists(i - k - 1, j - k - 1, n, m, mat);
                int c = ifexists(i - k - 1, j + k, n, m, mat);
                int d = ifexists(i + k, j - k - 1, n, m, mat);
                arr[i][j] = (a + b - c - d);
            }
        return arr;
    }
};