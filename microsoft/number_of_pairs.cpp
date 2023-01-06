// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    vi ans;
    int findpath(vector<vector<int>> &edges, int idx, int par)
    {
        if (idx == 0)
        {
            return 1;
        }
        int flag = 0;
        for (auto x : edges[idx])
        {
            if (x != par)
            {
                if (findpath(edges, x, idx))
                {
                    ans.push_back(x);
                    flag = 1;
                }
            }
        }
        return flag;
    }
    long long findprofit(vector<vector<int>> &edges, int idx, int par, vector<int> &amount)
    {

        long long prft = LLONG_MIN;
        for (auto x : edges[idx])
        {
            if (x != par)
            {
                long long var = findprofit(edges, x, idx, amount);
                if (var > prft)
                    prft = var;
            }
        }
        if (prft == LLONG_MIN)
            return amount[idx];
        return prft + amount[idx];
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        vi v;
        int n = edges.size() + 1;
        vii adj(n);
        ans = v;
        for (auto k : edges)
        {
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        int a = findpath(adj, bob, bob);
        ans.push_back(bob);
        reverse(ans.begin(), ans.end());
        if (ans.size() % 2)
            amount[ans[ans.size() / 2]] /= 2;

        for (int i = 0; i < (ans.size()) / 2; i++)
        {
            amount[ans[i]] = 0;
        }

        return findprofit(adj, 0, 0, amount);
    }
};
int main()
{

    return 0;
}
