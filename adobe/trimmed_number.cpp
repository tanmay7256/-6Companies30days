class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums[0].size();
        for (auto q : queries)
        {
            vector<pair<string, int>> v;
            for (int i = 0; i < nums.size(); i++)
            {
                v.push_back({nums[i].substr(n - q[1], q[1]), i});
            }
            sort(v.begin(), v.end());
            ans.push_back(v[q[0] - 1].second);
        }
        return ans;
    }
};