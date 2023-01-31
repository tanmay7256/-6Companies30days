// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    unordered_map<int, vector<pair<int, int>>> umap;
    map<pair<pair<int, string>, int>, int> dp;

    void make_map(vector<vector<int>> &flights)
    {
        for (int i = 0; i < flights.size(); i++)
        {
            vector<int> v = flights[i];
            umap[v[0]].push_back({v[1], v[2]});
        }
    }
    int mx;
    int find(int node, int dst, int k, int currk, string &vis, int sum)
    {
        if ((currk - 1 > k) || (sum > mx))
            return -1;
        if (dp.find({{currk, vis}, node}) != dp.end())
            return dp[{{currk, vis}, node}];
        if (node == dst)
        {
            mx = min(mx, sum);
            return 0;
        }
        vis[node] = '1';
        int ans = INT_MAX;
        for (auto p : umap[node])
        {
            if (vis[p.first] == '0')
            {
                int a = find(p.first, dst, k, currk + 1, vis, sum + p.second);
                if (a != -1)
                    ans = min(ans, a + p.second);
            }
        }
        vis[node] = '0';
        if (ans == INT_MAX)
            ans = -1;
        return dp[{{currk, vis}, node}] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        mx = INT_MAX;
        umap.clear();
        dp.clear();
        make_map(flights);
        string vis(n, '0');
        return find(src, dst, k, 0, vis, 0);
    }
};
int main()
{

    return 0;
}
