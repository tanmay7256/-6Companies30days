// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &arr)
    {
        int n = arr.size();
        map<pii, int> umap;
        map<vector<int>, int> mp;
        long long area = 0;
        for (auto v : arr)
        {
            area += abs(long(v[0] - v[2]) * (long(v[1] - v[3])));
            umap[{v[0], v[1]}]++;
            umap[{v[2], v[3]}]++;
            umap[{v[2], v[1]}]++;
            umap[{v[0], v[3]}]++;
            if (mp[v])
                return 0;
            mp[v] = 1;
        }
        vector<vector<int>> ans;
        int c = 0;
        for (auto p : umap)
        {
            if (p.second == 1)
            {
                c++;
                ans.push_back({p.first.first, p.first.second});
            }
            if (c > 4)
                return 0;
        }
        if (c != 4)
            return 0;
        sort(ans.begin(), ans.end());
        long long temp = abs(long(ans[0][1] - ans[1][1]) * (long(ans[2][0] - ans[0][0])));
        if (temp != area)
            return 0;
        return 1;
    }
};
int main()
{

    return 0;
}
