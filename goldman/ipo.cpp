class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &p, vector<int> &c)
    {
        int n = p.size();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {c[i], p[i]};
        }
        int j = 0, i = 0;
        sort(v.begin(), v.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        while (k--)
        {
            while (i < n && v[i][0] <= w)
            {
                if (v[i][1] > 0)
                    pq.push({v[i][1], v[i][0]});
                i++;
            }
            if (!(pq.empty()))
            {
                pair<int, int> p = pq.top();
                pq.pop();
                // cout<<p.first<<endl;
                w += p.first;
            }
        }
        return w;
    }
};