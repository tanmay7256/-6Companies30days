// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    vi visited;
    int find(vector<vector<int>> &edges, int idx)
    {
        if (visited[idx] == -1)
            return false;
        if (visited[idx])
            return true;
        int flag = 0;
        visited[idx] = -1;
        for (auto x : edges[idx])
        {
            int f = find(edges, x);
            if (f == 0)
            {
                visited[idx] = -1;
                return false;
            }
        }
        visited[idx] = 1;
        return true;
    }
    bool canFinish(int num, vector<vector<int>> &pre)
    {

        int n = pre.size() + 1;
        visited = vi(num, 0);
        vii adj(num);
        for (auto k : pre)
        {
            adj[k[0]].push_back(k[1]);
        }
        int flag = 1;
        for (int i = 0; i < num; i++)
        {
            if (!find(adj, i))
                flag = 0;
        }
        return flag;
    }
};
int main()
{

    return 0;
}
