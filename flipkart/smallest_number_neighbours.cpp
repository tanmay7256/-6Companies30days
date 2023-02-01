class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int dt)
    {
        int N = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, N));
        for (auto i : edges)
        {
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        int city = -1, ct = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i && dist[i][j] <= dt)
                    count++;
            }
            if (count <= ct)
            {
                ct = count;
                city = i;
            }
        }
        return city;
    }
};