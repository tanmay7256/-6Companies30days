class StockPrice
{
public:
    int currtm = -1, currpr;
    multiset<int> mn;
    multiset<int, greater<int>> mx;
    unordered_map<int, int> umap;
    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {
        if (timestamp <= currtm && umap[timestamp])
        {
            mn.erase(mn.find(umap[timestamp]));
            mx.erase(mx.find(umap[timestamp]));
        }
        if (timestamp >= currtm)
        {
            currtm = timestamp;
            currpr = price;
        }
        umap[timestamp] = price;
        mn.insert(price);
        mx.insert(price);
    }

    int current()
    {
        return currpr;
    }

    int maximum()
    {
        auto p = mx.begin();
        return *p;
    }

    int minimum()
    {
        auto p = mn.begin();
        return *p;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */