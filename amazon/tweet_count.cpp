class TweetCounts
{
public:
    unordered_map<string, multiset<int>> umap;
    TweetCounts()
    {
    }

    void recordTweet(string tweetName, int time)
    {
        umap[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
    {
        multiset<int> st = umap[tweetName];
        int n;
        if (freq == "minute")
            n = 60;
        else if (freq == "hour")
            n = 3600;
        else if (freq == "day")
            n = 86400;
        vector<int> ans;
        auto initial = lower_bound(st.begin(), st.end(), startTime);
        while (startTime <= endTime)
        {
            int t = *initial, c = 0;
            while (initial != st.end() && t < (startTime + n) && t <= endTime)
            {
                initial++;
                t = *initial;
                c++;
            }
            startTime += n;
            ans.push_back(c);
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */