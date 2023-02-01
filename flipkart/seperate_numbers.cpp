class Solution
{
public:
    int N = 1e9 + 7;
    vector<vector<int>> dp;
    int find(string &num, int idx, int n, int size = 1)
    {
        if (idx == (n))
            return 1;
        if (((num.size() - idx) < size) || num[idx] == '0')
            return 0;
        if (dp[idx][size] != -1)
            return dp[idx][size];
        long long ans = 0;
        string str = (num.substr(idx, size));
        string mx = "";
        if (idx != 0)
            mx = num.substr(idx - size, size);
        if ((str >= mx))
        {
            ans += find(num, idx + size, n, size);
        }
        ans %= N;
        for (int i = idx + size; i < n; i++)
        {
            str += num[i];
            ans += find(num, i + 1, n, i - idx + 1);
            ans %= N;
        }
        return dp[idx][size] = ans;
    }
    int numberOfCombinations(string &num)
    {
        int n = num.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return find(num, 0, n);
    }
};