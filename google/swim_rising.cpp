class Solution
{
public:
    int iseligible(int x, int y, int n, vector<vector<int>> &vis)
    {
        if (x >= n || y >= n || x < 0 || y < 0 || vis[x][y])
            return 0;
        vis[x][y] = 1;
        return 1;
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        int flag = 1, t = 0;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        while (flag && !pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            if (p.first > t)
                t = p.first;
            cout << p.first << endl;
            if (p.second.first == n - 1 && p.second.second == n - 1)
                break;
            int x = p.second.first, y = p.second.second;
            if (iseligible(x - 1, y, n, vis))
                pq.push({grid[x - 1][y], {x - 1, y}});
            if (iseligible(x + 1, y, n, vis))
                pq.push({grid[x + 1][y], {x + 1, y}});
            if (iseligible(x, y + 1, n, vis))
                pq.push({grid[x][y + 1], {x, y + 1}});
            if (iseligible(x, y - 1, n, vis))
                pq.push({grid[x][y - 1], {x, y - 1}});
        }
        return t;
    }
};