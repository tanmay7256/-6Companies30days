// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        int n = s.length(), c = 0;
        unordered_map<string, int> umap;
        string t = "", temp = "";
        for (int i = 0; i < n; i++)
        {
            t += s[i];
            if (!umap[t])
            {
                umap[t] = 1;
                t = "";
                c++;
            }
        }
        return c;
    }
};
int main()
{

    return 0;
}
