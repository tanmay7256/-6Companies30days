// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 1;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            map<pair<double,double>, int> umap;
            int c = 0;
            for (int j = i + 1; j < n; j++)
            {
                double m, d;
                if ((points[j][0] - points[i][0]) == 0)
                {
                    m = -1;
                    d = 0;
                }
                else
                {
                    m = (double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]));
                    d = (points[i][1] - m * (points[i][0]));
                }
                umap[{m,d}]++;
                c = max(umap[{m,d}], c);
            }
            ans = max(ans, c + 1);
        }
        return ans;
    }
};
int main()
{

    return 0;
}
