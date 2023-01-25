int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
class Solution
{
public:
    long long cal(long long n)
    {
        long long ans = (n * (n - 1)) / 2;
        return ans;
    }
    int countNicePairs(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n);
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            umap[nums[i] - reverseDigits(nums[i])]++;
        }
        long long ans = 0;
        int N = 1e9 + 7;
        for (auto p : umap)
        {
            if (p.second > 1)
                ans += cal(p.second);
            ans %= N;
        }
        return ans;
    }
};