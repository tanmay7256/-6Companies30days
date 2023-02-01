class Solution
{
public:
    void mergesort(vector<int> &nums, int st, int en)
    {
        if (st >= en)
            return;
        int mid = (st + en) / 2;
        mergesort(nums, st, mid);
        mergesort(nums, mid + 1, en);
        vector<int> v;
        int i = st, j = mid + 1;
        while (i <= mid && j <= en)
        {
            if (nums[i] < nums[j])
            {
                v.push_back(nums[i]);
                i++;
            }
            else
            {
                v.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            v.push_back(nums[i]);
            i++;
        }
        while (j <= en)
        {
            v.push_back(nums[j]);
            j++;
        }
        for (int i = 0; i < en - st + 1; i++)
            nums[st + i] = v[i];
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};