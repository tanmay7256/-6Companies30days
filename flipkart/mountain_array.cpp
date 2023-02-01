/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int ans;
    void find(int st, int en, int tar, MountainArray &mountainArr, int flag)
    {
        while (st != en)
        {
            int a = mountainArr.get(st);
            int b = mountainArr.get(en);
            int mid = (st + en) / 2;
            int mide = mountainArr.get(mid);
            if (mide == tar)
            {
                ans = min(ans, mid);
                return;
            }
            if (flag)
            {
                if (mide > tar)
                    en = mid;
                else
                    st = (mid + 1);
            }
            else
            {
                if (mide > tar)
                    st = mid + 1;
                else
                    en = mid;
            }
        }
        if (st == en && mountainArr.get(st) == tar)
            ans = min(ans, st);
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        ans = INT_MAX;
        int n = mountainArr.length();
        int start = 0, end = n - 1;
        int flag = 2;
        while (start != end)
        {
            int mid = (start + end) / 2;
            if (((mid) == (n - 1)) || !flag)
                break;
            int a = mountainArr.get(mid);
            int b = mountainArr.get(mid + 1);
            if (a < b)
            {
                if (a >= target)
                {
                    find(start, mid, target, mountainArr, 1);
                    flag--;
                }
                start = mid + 1;
            }
            else
            {
                if (a > target)
                {
                    find(mid + 1, end, target, mountainArr, 0);
                    flag--;
                }
                end = mid;
            }
        }
        if (start == end && mountainArr.get(start) == target)
            ans = min(ans, start);
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};