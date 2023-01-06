// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;
#define ll long long

ll mod = 1e9 + 7;
class Solution
{
public:
    ll dijsktra(vector<vector<pair<int, int>>> &edges, ll idx, ll par, ll n)
    {
        set<pair<long long, long long>> s;
        s.insert({0, 0});
        vi visited(n, 0), dist(n, 0), pending(n, 0), dp(n, 0);
        dp[0] = 1;
        while (!(s.empty()))
        {
            pair<long long, long long> p = *(s.begin());
            s.erase(s.begin());
            visited[p.second] = 1;
            pending[p.second] = 0;
            // cout<<"  "<<p.first<<endl;
            for (auto x : edges[p.second])
            {
                if (pending[x.first])
                {
                    if (dist[x.first] == (p.first + x.second) % mod)
                    {
                        dp[x.first] += dp[p.second];
                        dp[x.first] %= mod;
                    }
                    else if (dist[x.first] > (p.first + x.second) % mod)
                    {
                        s.erase({dist[x.first], x.first});
                        dist[x.first] = (p.first + x.second) % mod;
                        s.insert({dist[x.first], x.first});
                        dp[x.first] = dp[p.second];
                    }
                }
                else if (!visited[x.first])
                {
                    // cout<<x.first<<" "<<(p.second + x.second)<<endl;
                    dist[x.first] = (p.first + x.second) % mod;
                    pending[x.first] = 1;
                    s.insert({dist[x.first], x.first});
                    dp[x.first] = dp[p.second];
                }
            }
        }
        return dp[n - 1] % mod;
    }

    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto k : roads)
        {
            adj[k[0]].push_back({k[1], k[2]});
            adj[k[1]].push_back({k[0], k[2]});
        }
        return dijsktra(adj, 0, 0, n);
    }
};
int main()
{

    return 0;
}
