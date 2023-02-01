class Solution
{
public:
    vector<int> arr;

    Solution(vector<int> &nums)
    {
        arr = nums;
    }

    vector<int> reset()
    {
        return arr;
    }
    vector<int> shuffle()
    {
        vector<int> ans = arr;
        unordered_map<int, int> umap;
        int a = 1e6 + 1;
        umap[a] = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            while (umap[a])
            {
                a = rand() % (arr.size());
            }
            ans[i] = arr[a];
            umap[a] = 1;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */