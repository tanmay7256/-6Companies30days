class Solution
{
public:
    string decToBinary(int n, int k)
    {
        string binaryNum(k, '0');
        int i = 0;
        while (n > 0)
        {
            binaryNum[i] += (n % 2);
            n = n / 2;
            i++;
        }
        return binaryNum;
    }
    bool hasAllCodes(string s, int k)
    {
        unordered_map<string, int> umap;
        if (s.size() < k)
            return 0;
        for (int i = 0; i < (s.size() - k + 1); i++)
        {
            string t = s.substr(i, k);
            umap[t] = 1;
        }
        for (int i = 0; i < pow(2, k); i++)
        {
            if (!umap[decToBinary(i, k)])
                return 0;
        }
        return 1;
    }
};