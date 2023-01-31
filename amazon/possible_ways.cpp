// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int st, en, N = 1e9 + 7;
    vector<vector<int>> dp;
    int find(int k, int d)
    {
        if (d > k || d < 0)
            return 0;

        if (k == 0)
        {
            if (d == 0)
                return 1;
            return 0;
        }
        if (dp[d][k] != -1)
            return dp[d][k];
        long long ans = find(k - 1, abs(d - 1));
        ans += find(k - 1, abs(d + 1));
        dp[d][k] = ans % N;
        return ans % N;
    }
    int numberOfWays(int startPos, int endPos, int k)
    {
        st = startPos;
        en = endPos;
        dp = vector<vector<int>>(1001, vector<int>(1001, -1));
        return find(k, abs(st - en));
    }
};
int main()
{

    return 0;
}
