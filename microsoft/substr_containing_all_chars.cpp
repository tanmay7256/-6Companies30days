// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length(), a = 0, b = 0, c = 0, cnt = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            if (s[j] == 'a')
                a++;
            else if (s[j] == 'b')
                b++;
            else if (s[j] == 'c')
                c++;
            j++;
            while (a && b && c)
            {
                cnt += (n - j + 1);
                // cout<<n-j+1<<" "<<i<<endl;
                if (s[i] == 'a')
                    a--;
                else if (s[i] == 'b')
                    b--;
                else if (s[i] == 'c')
                    c--;
                i++;
            }
        }
        return cnt;
    }
};
int main()
{

    return 0;
}
