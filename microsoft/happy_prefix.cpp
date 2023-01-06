// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int kmp(string &word)
    {
        vector<int> v(word.length(), 0);

        int index = 0;
        for (int i = 1; i < word.length();)
        {
            if (word[i] == word[index])
            {
                index++;
                v[i] = index;
                i++;
            }
            else
            {
                if (index != 0)
                    index = v[index - 1];
                else
                    i++;
            }
        }
        return v[v.size() - 1];
    }

    string longestPrefix(string s)
    {
        int a = kmp(s);

        return s.substr(0, a);
    }
};
int main()
{

    return 0;
}
