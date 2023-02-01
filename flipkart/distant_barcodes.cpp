class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        unordered_map<int, int> umap;
        priority_queue<pair<int, int>> pq;
        int n = barcodes.size();
        for (int i = 0; i < n; i++)
            umap[barcodes[i]]++;
        for (auto it = umap.begin(); it != umap.end(); it++)
        {
            pair<int, int> p = *it;
            pq.push({p.second, p.first});
        }
        vector<int> ans;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            if (pq.empty())
                break;
            pair<int, int> q = pq.top();
            pq.pop();
            ans.push_back(q.second);
            if (p.first != 1)
                pq.push({p.first - 1, p.second});
            if (q.first != 1)
                pq.push({q.first - 1, q.second});
        }
        return ans;
    }
};