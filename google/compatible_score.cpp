class Solution
{
public:
    map<pair<int, string>, int> umap;
    int find(vector<vector<int>> &stu, vector<vector<int>> &men, int idx, int n, int m, string mstr)
    {
        if (idx >= n)
            return 0;
        if (umap.find({idx, mstr}) != umap.end())
            return umap[{idx, mstr}];
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (mstr[i] == '0')
            {
                mstr[i] = '1';
                int ans = 0;
                for (int j = 0; j < m; j++)
                {
                    if (stu[idx][j] == men[i][j])
                        ans++;
                }
                int a = find(stu, men, idx + 1, n, m, mstr);
                mx = max(mx, ans + a);
                mstr[i] = '0';
            }
        }
        return umap[{idx, mstr}] = mx;
    }
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        umap.clear();
        int n = students.size(), m = students[0].size();
        string s(n, '0'), mstr(n, '0');
        return find(students, mentors, 0, n, m, mstr);
    }
};