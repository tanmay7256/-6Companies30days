class Solution
{
public:
    int dist(vector<int> n, vector<int> m)
    {
        return (n[0] - m[0]) * (n[0] - m[0]) + (n[1] - m[1]) * (n[1] - m[1]);
    }
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> umap;
            for (int j = 0; j < points.size(); j++)
            {
                umap[dist(points[i], points[j])]++;
            }
            for (auto p : umap)
            {
                if (p.second > 1)
                {
                    int n = p.second;
                    ans += (n) * (n - 1);
                }
            }
        }
        return ans;
    }
};