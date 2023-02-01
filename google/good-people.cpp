class Solution
{
public:
    int ans;
    void find(int n, vector<vector<int>> &st, vector<int> &v, int c)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (st[i][j] != 2 && st[i][j] != v[j])
                    {
                        // cout<<i<<j<<endl;
                        return;
                    }
                }
            }
        }
        ans = max(ans, c);
    }
    int maximumGood(vector<vector<int>> &statements)
    {
        int n = statements.size();
        ans = 0;
        long long b = pow(2, n);
        vector<int> v(n, 0);
        for (int i = 0; i < b; i++)
        {
            v = vector<int>(n, 0);
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                if ((i & (1 << j)))
                {
                    v[j] = 1;
                    c++;
                }
            }
            // cout<<i<<" "<<c<<" "<<ans<<endl;
            // if(i==6)
            find(n, statements, v, c);
        }
        return ans;
    }
};