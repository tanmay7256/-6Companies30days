class Solution
{
public:
    int dist(vector<int> a, vector<int> b)
    {
        return (a[1] - b[1]) * (a[1] - b[1]) + (a[0] - b[0]) * (a[0] - b[0]);
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> v = {p1, p2, p3, p4};
        unordered_map<int, int> umap;
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                umap[dist(v[i], v[j])]++;
            }
        }
        if (umap.size() > 2)
            return false;
        for (auto p : umap)
        {
            if (!(p.second == 4 || p.second == 2) || p.first == 0)
                return false;
        }
        return true;
    }
};