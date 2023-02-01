class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        long long ans = mass;
        for (int i = 0; i < arr.size(); i++)
        {
            if (ans < arr[i])
                return 0;
            ans += arr[i];
        }
        return 1;
    }
};