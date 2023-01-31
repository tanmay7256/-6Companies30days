// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    unordered_map<string, int> umap;
    int ans;
    void find(string &s, int i, int sum)
    {
        int n = s.length();
        if (i > n)
            return;
        if (i == n)
        {
            ans = max(ans, sum);
            return;
        }
        string t = "";
        for (i; i < n; i++)
        {
            t += s[i];
            if (umap[t] == 0)
            {
                umap[t] = 1;
                find(s, i + 1, sum + 1);
                umap[t] = 0;
            }
        }
    }
    int maxUniqueSplit(string &s, int i = 0)
    {
        umap.clear();
        ans = 0;
        find(s, i, 0);
        return ans;
    }
};
int main()
{

    return 0;
}
