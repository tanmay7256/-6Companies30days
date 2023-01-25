class Solution
{
public:
    vector<int> arr;
    void form()
    {
        arr = vector<int>(32);
        arr[0] = 1, arr[1] = 2, arr[2] = 3;
        int ones = 0, zeros = 1;
        for (int i = 3; i < 32; i++)
        {
            int tones = zeros;
            int tzeros = zeros + ones;
            ones = tones;
            zeros = tzeros;
            arr[i] = arr[i - 1] + ones + zeros;
        }
    }
    int flag = 1;
    int findforback(int n, int idx)
    {
        int b = log2(n) + 1;
        for (int i = idx + 2; i < b; i++)
        {
            if ((n & (1 << i)) && (n & (1 << (i - 1))))
                return 0;
        }
        return 1;
    }
    int findIntegers(int n)
    {
        if (flag)
        {
            form();
            flag = 0;
        }
        int b = log2(n) + 1;
        long long ans = 0;
        if (findforback(n, -1))
            ans++;
        for (int i = 0; i < b; i++)
        {

            if ((n & (1 << i)) && findforback(n, i))
            {
                ans += arr[i];
            }
        }
        return ans;
    }
};